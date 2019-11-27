//--------------------------------------------------------------------
// Code by WangYuan; Date:2019/8/30
// Input：网表文件地址+文件名
// Output：器件信息、网络信息、器件数量、网络数量
//--------------------------------------------------------------------




#if 1
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <vector>
#include <string>
#include "ReadProtelNetList.h"
#include "ReadCadenceProtelNetList.h"
#include "ReadNetListContext.h"


using namespace std;

int main()
{
    //string dir = "C:/Users/10057/Desktop/BStest.NET";
    string dir = "C:/Users/10057/Desktop/STM32.NET";
    //string dir = "C:/Users/10057/Desktop/AFG3500.NET";

    string type = "DefaultType";
    // string type = "CadenceProtel";
    //string type = "ProtelProtel";

    //ReadProtelNetList readProtel(dir);
    //ReadNetList *p=&readProtel;
    //int netNum = p->getNetNum();
    //cout << netNum << endl;
    //int compoNum = p->getComponentNum();
    //cout << compoNum << endl;
    //vector<vector<string>> netListInfo=p->getNetListInfo();         // 一个网络全部信息存在一个vector<string>中
    //vector<vector<string>> componentInfo=p->getComponentInfo();       // 存放器件名称及类型

    //cout<< netListInfo[0].size();
    //cout << netListInfo[1].size();


    //ReadCadenceProtelNetList readCadenceProtel(dir);            // 派生类对象
    //ReadNetList *p=&readCadenceProtel;                          // 基类指针
    //int netNum = p->getNetNum();
    //cout << netNum << endl;
    //int compoNum = p->getComponentNum();
    //cout << compoNum << endl;
    //vector<vector<string>> netListInfo=p->getNetListInfo();         // 一个网络全部信息存在一个vector<string>中
    //vector<vector<string>> componentInfo=p->getComponentInfo();       // 存放器件名称及类型


    ReadNetListContext * p= new ReadNetListContext(type, dir);
    ReadNetList * p0 =p->getNetListp();      // 指向 解析相应网表的派生类 的基类指针
    int netNum = p0->getNetNum();
    cout << netNum << endl;
    int compoNum = p0->getComponentNum();
    cout << compoNum << endl;
    vector<vector<string>> netListInfo = p0->getNetListInfo();         // 一个网络全部信息存在一个vector<string>中
    vector<vector<string>> componentInfo = p0->getComponentInfo();       // 存放器件名称及类型
    bool status = p0->outfile_to_txt("C:/Users/10057/Desktop/test2.txt");
    if (!status)
    {
        cout << "写入文本文件成功" << endl;
    }

    //cout << "器件信息" << endl;
    //for (unsigned int i = 0; i != componentInfo.size(); ++i)
    //{
    //    cout << "第" << i << "个元器件" << endl;
    //    for (unsigned int j = 0; j != componentInfo[i].size(); ++j)
    //    {
    //        cout << componentInfo[i][j] << " ";
    //    }
    //    cout << endl;
    //}
    //cout << "网络信息" << endl;
    //for (unsigned int i = 0; i != netListInfo.size(); ++i)
    //{
    //    cout <<"第"<<i<<"个网络"<< endl;
    //    for (unsigned int j = 0; j != netListInfo[i].size(); ++j)
    //    {
    //        cout << netListInfo[i][j] << " ";
    //    }
    //    cout << endl;
    //    
    //}



    delete p;
    p = nullptr;
    p0 = nullptr;

    system("pause");

}

#endif


#if 0
#include <iostream>
#include <fstream>

using namespace std;
int main()
{
    ofstream outfile;
    outfile.open("C:/Users/10057/Desktop/test1.txt", ofstream::out| ofstream::app);
    outfile << "hh\x20hh" ;

}



#endif