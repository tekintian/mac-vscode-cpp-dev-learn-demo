#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
    char data[100];
    ofstream outfile;                      // 以写模式定义outfile
    outfile.open("../assets/outfile.txt"); // 如果文件不存在,则自动创建; 如果文件存在,则清空原来的文件

    std::cout << "Please input you name:" << std::endl;
    cin.getline(data, 100);  //获取用户输入的一行数据   getline()函数从外部读取一行
    outfile << data << endl; // 向文件写入用户输入的数据

    std::cout << "Please input you age:" << std::endl;
    cin >> data;  // 获取输入的数据
    cin.ignore(); //忽略掉之前读语句留下的多余字符

    // 再次向文件写入用户输入的数据
    outfile << data << endl;
    outfile.close();

    std::cout << "=======读取文件=====" << std::endl;
    ifstream infile;
    infile.open("../assets/outfile.txt");
    std::cout << "reading from file" << std::endl;
    infile >> data; // 使用流提取符号  >> 提取数据到 data ; 每执行一次提取一行数据

    // 在屏幕上写入数据
    cout << data << endl;

    // 再次从文件读取数据，并显示它
    infile >> data;
    cout << data << endl;

    // 关闭打开的文件
    infile.close();

    return 0;
}
