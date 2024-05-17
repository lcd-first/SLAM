#include <iostream>
#include <Eigen/Dense>

using  namespace std;
int main() {
    //定义一个三维向量， 3 代表 3维  d代表  double 类型
    Eigen::Vector3d v1(1.0,2.0,3.0);

    Eigen::Vector3d v2(2.0,3.0,4.0);

    //相加
    cout<<"v1 = "<<endl<<v1;
    cout<<endl;
    cout<<"v2 = "<<endl<<v2;
    Eigen::Vector3d sum=v1+v2;
    cout<<endl;
    cout<<"v1+v2 = "<<endl<<sum;
    cout<<endl;
    //内积 点乘
    double dot_product = v1.dot(v2);
    cout<< "v1*v2 = " <<dot_product<<endl;
    //外积 叉乘
    Eigen::Vector3d corss_product = v1.cross(v2);
    cout<<endl;
    cout<<"a X b = "<<endl<<corss_product;



    return 0;
}
