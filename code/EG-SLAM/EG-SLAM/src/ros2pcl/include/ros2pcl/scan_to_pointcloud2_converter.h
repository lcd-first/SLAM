//#ifndef 

#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>

#include <pcl_ros/point_cloud.h>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>


class ScanToPointCloud2Converter {
    
    typedef pcl::PointXYZ PointT;  // pcl点 的数据结构
    typedef pcl::PointCloud<PointT> PointCloudT;   //pcl 点云数据结构

    private:
        ros::NodeHandle node_handle_;  //ros 
        ros::NodeHandle private_node_; //私有
        ros::Subscriber laser_scan_subscriber_; //订阅雷达消息
        ros::Publisher pointcloud2_publisher_; //发布转换过后的点云数据
        PointT invalid_point_;  //保存无效点的值，为nan 
    public:
        ScanToPointCloud2Converter();
        ~ScanToPointCloud2Converter();
        void ScanCallback(const sensor_msgs::LaserScan::ConstPtr& scan_msgs);

};


