#include <ros2pcl/scan_to_pointcloud2_converter.h>
#include <limits>  // 获取基础类型中最大值 最小值

ScanToPointCloud2Converter::ScanToPointCloud2Converter() : private_node_("~") {

    ROS_INFO_STREAM("\033[1;32m----> Scan to PointCloud2 Converter.\033[0m");

    laser_scan_subscriber_ = node_handle_.subscribe("laser_scan",1,&ScanToPointCloud2Converter::ScanCallback,this);

    pointcloud2_publisher_= node_handle_.advertise<PointCloudT>("pointcloud2_converted",1,this);

    invalid_point_.x= std::numeric_limits<float>::quiet_NaN();
    invalid_point_.y= std::numeric_limits<float>::quiet_NaN();
    invalid_point_.z= std::numeric_limits<float>::quiet_NaN();
}
//析构函数
ScanToPointCloud2Converter::~ScanToPointCloud2Converter() {
    ROS_INFO("Destroying ScanToPintCloud2Converter");
}

void ScanToPointCloud2Converter::ScanCallback(const sensor_msgs::LaserScan::ConstPtr &scan_msg) {

    // 使用Boost 库 创建共享指针  用来指向一个PointCloudT类型的对象
    PointCloudT::Ptr cloud_msg = boost::shared_ptr<PointCloudT>(new PointCloudT());

    cloud_msg->points.resize(scan_msg->ranges.size());
    
    for(unsigned int i =0; i<scan_msg->ranges.size();i++)
    {
        // 声明一个cloud_msg 第i格点的引用 
        PointT &point_tmp = cloud_msg->points[i];
        // 获取scan第i 个点的距离值
        float range = scan_msg->ranges[i];

        //判断是否为无效点
        if(!std::isfinite(range)) {
            point_tmp= invalid_point_;
            continue;
        }

        if(range >scan_msg->range_min && range<scan_msg->range_max) {

            float angle = scan_msg->angle_min +i*scan_msg->angle_increment;
            point_tmp.x= range*cos(angle);
            point_tmp.y= range*sin(angle);
            point_tmp.z = 0.0;
        }
        else
            //否则为无效点
            point_tmp = invalid_point_;

    }
    
    cloud_msg->width = scan_msg->ranges.size();
    cloud_msg->height = 1 ;
    cloud_msg ->is_dense = false; 
    pcl_conversions::toPCL(scan_msg->header, cloud_msg->header);
    pointcloud2_publisher_.publish(cloud_msg);

}






int main(int argc,char **argv) {

    ros::init(argc,argv,"ros2pcl"); 
    ScanToPointCloud2Converter scan_to_pointcloud2_converter;

    ros::spin();
    return 0;

}