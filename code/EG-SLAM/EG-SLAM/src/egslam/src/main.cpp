#include "ros/ros.h"

// 利用第一帧雷达数据计算扫描角度和最值等固定参数
void ScanMatchPLICP::CreateCache(const sensor_msgs::LaserScan::ConstPtr &scan_msg)
{
    //这里计算sin和cos值的目的是因为在后续需要用到这些角度值把雷达的数据转换为
    //icp算法需要的数据
    a_cos_.clear();
    a_sin_.clear();
    double angle;
 
    for (unsigned int i = 0; i < scan_msg->ranges.size(); i++)
    {
        angle = scan_msg->angle_min + i * scan_msg->angle_increment;
        a_cos_.push_back(cos(angle));
        a_sin_.push_back(sin(angle));
    }
 
	//保存扫描距离的最大和最小的目的是后续用这两个值来判断一个雷达数据是否有效
    input_.min_reading = scan_msg->range_min;
    input_.max_reading = scan_msg->range_max;
}

//发布base_link 到laser _link 的静态坐标变换
bool ScanMatchPLICP::GetBaseToLaserTf(const std::string &frame_id)
{
    ros::Time t = ros::Time::now();
 
    geometry_msgs::TransformStamped transformStamped;
    transformStamped.header.stamp = ros::Time::now();
    transformStamped.header.frame_id = frame_id;
    transformStamped.child_frame_id = base_frame;
    transformStamped.transform.translation.x = 0.0;
    transformStamped.transform.translation.y = 0.0;
    transformStamped.transform.translation.z = 0.0;
    transformStamped.transform.rotation.x = 0.0;
    transformStamped.transform.rotation.y = 0.0;
    transformStamped.transform.rotation.z = 0.0;
    transformStamped.transform.rotation.w = 1.0;
    tf2::fromMsg(transformStamped.transform, base_to_laser_);
    laser_to_base_ = base_to_laser_.inverse();
    return true;
}



void ScanMatchPLICP::LaserScanToLDP(const sensor_msgs::LaserScan::ConstPtr &scan_msg, LDP &ldp)
{
    unsigned int n = scan_msg->ranges.size();
    ldp = ld_alloc_new(n);
 
    for (unsigned int i = 0; i < n; i++)
    {
        // calculate position in laser frame
        double r = scan_msg->ranges[i];
 
        if (r > scan_msg->range_min && r < scan_msg->range_max)
        {
            // 填充雷达数据
            ldp->valid[i] = 1;
            ldp->readings[i] = r;
        }
        else
        {
            ldp->valid[i] = 0;
            ldp->readings[i] = -1; // for invalid range
        }
 
        ldp->theta[i] = scan_msg->angle_min + i * scan_msg->angle_increment;
        ldp->cluster[i] = -1;
    }
 
    ldp->min_theta = ldp->theta[0];
    ldp->max_theta = ldp->theta[n - 1];
 
    ldp->odometry[0] = 0.0;
    ldp->odometry[1] = 0.0;
    ldp->odometry[2] = 0.0;
 
    ldp->true_pose[0] = 0.0;
    ldp->true_pose[1] = 0.0;
    ldp->true_pose[2] = 0.0;
}


void ScanMatchPLICP::LaserScanToLDP(const sensor_msgs::LaserScan::ConstPtr &scan_msg, LDP &ldp)
{
    unsigned int n = scan_msg->ranges.size();
    ldp = ld_alloc_new(n);
 
    for (unsigned int i = 0; i < n; i++)
    {
        // calculate position in laser frame
        double r = scan_msg->ranges[i];
 
        if (r > scan_msg->range_min && r < scan_msg->range_max)
        {
            // 填充雷达数据
            ldp->valid[i] = 1;
            ldp->readings[i] = r;
        }
        else
        {
            ldp->valid[i] = 0;
            ldp->readings[i] = -1; // for invalid range
        }
 
        ldp->theta[i] = scan_msg->angle_min + i * scan_msg->angle_increment;
        ldp->cluster[i] = -1;
    }
 
    ldp->min_theta = ldp->theta[0];
    ldp->max_theta = ldp->theta[n - 1];
 
    ldp->odometry[0] = 0.0;
    ldp->odometry[1] = 0.0;
    ldp->odometry[2] = 0.0;
 
    ldp->true_pose[0] = 0.0;
    ldp->true_pose[1] = 0.0;
    ldp->true_pose[2] = 0.0;
}














int main(int argc, char *argv[])
{
    //执行 ros 节点初始化
    ros::init(argc,argv,"hello");
    ros::NodeHandle node_handle_;
    ros::Subscriber laser_scan_subscriber;
    laser_scan_subscriber_ = node_handle_.subscribe("/scan", 1, &ScanMatchPLICP::ScanCallback, this);





    return 0;
}
