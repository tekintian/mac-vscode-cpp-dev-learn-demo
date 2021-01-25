#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    //3维数组内存分配和释放
    int i,j,k; //p[2][3][4]

    int ***p;
    p = new int **[2];
    for(i=0;i<2;i++){
        p[i] = new int*[3];
        for(j=0;j<3;j++){
            p[i][j]=new int[4];
        }
    }
    //输出 p[i][j][k] 三维数据
    for(i=0;i<2;i++){
      for(j=0;j<3;j++){
            for(k=0;k<4;k++){
                p[i][j][k]=i+j+k;
                if(k==0) cout<<endl; //如果是第一行 则输出换行符
                cout<<p[i][j][k]<<" \t";
            }
        }
    }
    //释放内存
    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            delete []p[i][j];
        }
       delete []p[i];
    }
    // for(i=0;i<2;i++){
    //     delete []p[i];
    // }
    delete[]p;

    return 0;
}