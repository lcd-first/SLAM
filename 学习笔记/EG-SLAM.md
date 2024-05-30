# EG—SLAM



# 资料：

```
https://blog.csdn.net/tiancailx/category_10582260.html

https://blog.csdn.net/tiancailx/article/details/110822624

https://github.com/xiangli0608/Creating-2D-laser-slam-from-scratch
```



# 目的： 

1. 深入学习SLAM
2. 实际编写SLAM，提高代码工程能力







# 简介：

从零二维激光SLAM 算法





# 算法流程： 

前端：

前端，通过PCL-ICP算法， 进行帧间匹配求得相对位姿变换

后端：

激光SLAM中，后端进行优化和建图，主流的SLAM框架会单独分一个线程来执行后端，因为不管是建图还是优化，都需要占用相当的计算资源，为了保证实时性，

采取多线程，限制后端优化和建图的规模，也有很多小tricks ，比如建立关键帧,采用滑动窗口， 丢掉观测只优化位姿图等等‘

建图： 本位采用了经典的占据栅格地图，其本质就是连续的地图离散化，变成一个一个栅格，如果被激光hit，则设计那个格子为占据，否则则设定为空闲，没有被激光扫到的格子状态为未知，如果用三个值来表示的化，占据的就是100，空闲的是0， 未知的是 -1 ， 随后我们维护一个数组，把每个格子的状态放进去，在建图的时候把这个一维数组进行二维展开，再根据每个格子的状态用颜色进行区分（系统自动完成），就完成了一个最简单的占据栅格地图。





回环

前端进行扫描匹配，后端进行优化，回环消除累计误差



## 1. 提取关键帧





![image-20240522100458236](D:\SLAM\学习笔记\EG-SLAM.assets\image-20240522100458236.png)







![image-20240522100504689](D:\SLAM\学习笔记\EG-SLAM.assets\image-20240522100504689.png)



## 2.  使用PCL 进行雷达消息类型转换

​	sensor_msgs/LaserScan转换成的sensor_msgs/PointCloud2









## 3. ICP 帧间匹配

使用转换格式后的点云，调用ICP算法进行相邻两帧雷达数据间坐标变换的计算

![image-20240528110242952](D:\SLAM\学习笔记\EG-SLAM.assets\image-20240528110242952.png)



## 4. PL-ICP的帧建匹配

ICP的计算时间以及精度都不太好， 使用ICP改进算法 PL-ICL算法来计算相邻帧间的坐标变换PL

PL-ICP 使用点到线距离最小的方式进行ICP的计算，收敛速度快，精度高



PL-ICP 作者开源资料： 

```
https://censi.science/software/csm/.
wiki 地址：
http://wiki.ros.org/scan_tools?distro=kinetic
```

功能包介绍：

- laser_ortho_projector: 将切斜的雷达数据投影到平面上．
- laser_scan_matcher: 基于pl-icp的扫描匹配的实现，并进行了位姿累加
- laser_scan_sparsifier: 对雷达数据进行稀疏处理
- laser_scan_splitter: 将一帧雷达数据分段，并发布出去
- ncd_parser: 读取New College Dataset，转换成ros的scan 与 odometry 发布出去
- polar_scan_matcher: 基于Polar Scan Matcher的扫描匹配器的ros实现
- scan_to_cloud_converter: 将 sensor_msgs/LaserScan 数据转成 sensor_msgs/PointCloud2 的数据格式
  



![image-20240529112023302](D:\SLAM\学习笔记\EG-SLAM.assets\image-20240529112023302.png)







## 5. PL-ICP的激光雷达里程计















































