#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <map>
#include <vector>
#include <chrono>  // 时间库函数 以精确到 纳秒，微秒，毫秒，秒，分钟，小时

#define max_scan_count 1500  //雷达数据个数最大值

struct smoothness_t {
    float value;
    size_t index;
}  //定义键值对

struct by_value {
    bool operator()(smoothness_t const &left, smoothness_t const &right) {
        return left.value< right.value;
    }
}  //排序规则， 从小到大进行排序

// 定义一个雷达类
class LaserScan {

    private:
        ros::NodeHandle node_handle_;  //ros 句柄
        ros::NodeHandle private_node_; //ros 私有句柄
        ros::Subscriber laser_scan_subscriber_;  //声明订阅雷达原始点云
        ros::Publisher  feature_scan_publisher_;  //特征点发布
        float edge_threshold_;  //提取角点的阈值
    public:
        LaserScan();  //默认构造函数
        ~LaserScan(); //析构函数
        void ScanCallback(const sensor_msgs::LaserScan::ConstPtr &scan_msg);  //雷达回调函数

}
// 构造函数
LaserScan::LaserScan() : private_node_("~") {
    ROS_INFO_STREAM("点云抽取关键帧");
    //原始点云订阅
    laser_scan_subscriber_ = node_handle_.subscribe("laser_scan",1,&LaserScan::ScanCallback,this);
    //关键帧发布
    feature_scan_publisher_ = node_handle_.advertise<sensor_msgs::LaserScan>("feature_scan",1,this);
    //设置角点阈值为1.0
    edge_threshold_ = 1.0; 

}
//析构函数
LaserScan::~LaserScan() {

}
// 原始点云回调函数
LaserScan::ScanCallback(const sensor_msgs::LaserScan::ConstPtr &scan_msg) {
    
    std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();  //时间起点 
    
    std::vector<smoothness_t> scan_smoothness_(max_scan_count);  //存储每个点的曲率和索引
    float *scan_curvature_ = new float[max_scan_count];  //存储每个点的曲率

    std:map<int,int> map_index;  //有效点的索引，对应的scan 实际索引  map容器
    int cout = 0; // 有效点的索引
    float  new_scan[max_scan_count];  //存储scan数据的距离值

    //获取当前帧实际点数
    int scan_count = scan_msg->ranges.size();
    //筛选有效点
    for(int i=0; i<scan_count;i++) {
        // isfinite 检查一个数是否为有限值，正常返回ture 不正常 如nan inf -inf 返回false    
        if(!std::isfinite(scan_msg->ranges[i])) {
            continue;
        }
        
        map_index[cout]=i; //保存有效值的索引 
        new_scan[cout] = scan_msg->ranges[i];  //保存有效点的距离值
        cout++;  

    }
    //计算曲率， 通过计算当前点的前后5个点距离值的偏差程度来代表曲率
    //如果是球面，则当前点周围的10个点的距离值之和， 减去当前点距离的10倍数 等于0 
    for(int i =5;i<cout-5;i++) {
        float diff_range = new_scan[i-5]+new_scan[i-4] +
                           new_scan[i-3]+ new_scan[i-2] +
                           new_scan[i-1] - new_scan[i]*10 +
                           new_scan[i+1] + new_scan[i+2]+
                           new_scan[i+3]+new_scan[i+4]+
                           new_scan[i+5];
        scan_curvature_[i] = diff_range*diff_range;  //相乘得到平方数
        scan_smoothness_[i].value = scan_curvature_[i];
        scan_smoothness_[i].index= i;
    }

    // 声明一个临时的sensor_msgs::LaserScan变量,用于存储特征提取后的scan数据,并发布出去,在rviz中进行显示
    sensor_msgs::LaserScan corner_scan;
    corner_scan.header = scan_msg->header;
    corner_scan.angle_min = scan_msg->angle_min;
    corner_scan.angle_max = scan_msg->angle_max;
    corner_scan.angle_increment = scan_msg->angle_increment;
    corner_scan.range_min = scan_msg->range_min;
    corner_scan.range_max = scan_msg->range_max;

    // 对float[] 进行初始化
    corner_scan.ranges.resize(max_scan_count);


   // 进行角点的提取,将完整的scan分成6部分,每部分至多提取20个角点
    for (int j = 0; j < 6; j++)
    {
        int start_index = (0 * (6 - j) + count * j) / 6;
        int end_index = (0 * (5 - j) + count * (j + 1)) / 6 - 1;
        // std::cout << "start_index: " << start_index << " end_index: " << end_index << std::endl;

        if (start_index >= end_index)
            continue;

        // 将这段点云按照曲率从小到大进行排序
        std::sort(scan_smoothness_.begin() + start_index,
                  scan_smoothness_.begin() + end_index, by_value());

        int largestPickedNum = 0;
        // 最后的点 的曲率最大，如果满足条件，就是角点
        for (int k = end_index; k >= start_index; k--)
        {
            int index = scan_smoothness_[k].index;
            if (scan_smoothness_[k].value > edge_threshold_)
            {
                // 每一段最多只取20个角点
                largestPickedNum++;
                if (largestPickedNum <= 20)
                {
                    corner_scan.ranges[map_index[index]] = scan_msg->ranges[map_index[index]];
                }
                else
                {
                    break;
                }
            }
        }
    }

    // 将提取后的scan数据发布出去
    feature_scan_publisher_.publish(corner_scan);
    std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
    std::chrono::duration<double> time_used = std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time);
    // std::cout<<"处理一次数据用时: "<< time_used.count() << " 秒。" << std::endl;

}


int main(int argc, char **argv) {

    //特征点提取
    ros::init(argc,argv,"key_points");
    LaserScan laser_scan;

    ros::spin();  //程序开始等待，有订阅消息都会执行一次回调函数

    return 0;
}