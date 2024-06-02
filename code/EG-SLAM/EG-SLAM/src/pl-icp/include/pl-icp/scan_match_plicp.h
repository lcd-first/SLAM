#include <cmath>
#include <vector>
#include <chrono>

// ros
#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/TwistStamped.h>
// tf2
#include <tf2/utils.h>
#include <tf2/LinearMath/Transform.h>
#include <tf2_ros/transform_listener.h>
#include "tf2_ros/transform_broadcaster.h"
// csm
#include <csm/csm_all.h>


#undef min
#undef max

class ScanMatchPLICP
{
    
private:
    ros::NodeHandle node_handle_;           // ros中的句柄
    ros::NodeHandle private_node_;          // ros中的私有句柄
    ros::Subscriber laser_scan_subscriber_; // 声明一个Subscriber

    ros::Time last_icp_time_;               // 上次的时间戳

    bool initialized_;                      // 是否初始化的标志

    std::vector<double> a_cos_;             // 保存下来雷达各个角度的cos值
    std::vector<double> a_sin_;             // 保存下来雷达各个角度的sin值

    std::chrono::steady_clock::time_point start_time_;
    std::chrono::steady_clock::time_point end_time_;
    std::chrono::duration<double> time_used_;

    // csm
    sm_params input_;
    sm_result output_;
    LDP prev_ldp_scan_;

    void InitParams();
    void CreateCache(const sensor_msgs::LaserScan::ConstPtr &scan_msg);
    void LaserScanToLDP(const sensor_msgs::LaserScan::ConstPtr &scan_msg, LDP &ldp);
    void ScanMatchWithPLICP(LDP &curr_ldp_scan, const ros::Time &time);

public:
    ScanMatchPLICP();
    ~ScanMatchPLICP();

    void ScanCallback(const sensor_msgs::LaserScan::ConstPtr &scan_msg);
};

