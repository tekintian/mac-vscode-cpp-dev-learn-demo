#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
   int **arr; // 定义二维数组指针, 假定二维数据为 arr[10][3]
   int i,j; // 循环变量定义
   arr = new int *[10]; //为第一层数组分配内存
    // 为第二维数组分配内存
   for(i=0;i<10;i++){
       arr[i] = new int[3];
    }
    // 增加数据
    for(i=0;i<10;i++){
        for(j=0;j<3;j++){
           arr[i][j]=j*i;
        }
    }
    //打印数据集
    for(i=0;i<10;i++){
        for(j=0;j<3;j++){
           if(j==0) cout<<endl;
           cout<<arr[i][j]<<"\t";
        }
    }

    cout<<"\n释放内存\n";
    // 释放内存
    for(int i=0;i<10;i++){
        delete []arr[i];
    }
    delete []arr;
    cout<<"释放内存完毕\n";
    return 0;
}
