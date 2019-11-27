//--------------------------------------------------------------------
// Code by WangYuan; Date:2019/8/30
// Input�������ļ���ַ+�ļ���
// Output��������Ϣ��������Ϣ��������������������
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
    //vector<vector<string>> netListInfo=p->getNetListInfo();         // һ������ȫ����Ϣ����һ��vector<string>��
    //vector<vector<string>> componentInfo=p->getComponentInfo();       // ����������Ƽ�����

    //cout<< netListInfo[0].size();
    //cout << netListInfo[1].size();


    //ReadCadenceProtelNetList readCadenceProtel(dir);            // ���������
    //ReadNetList *p=&readCadenceProtel;                          // ����ָ��
    //int netNum = p->getNetNum();
    //cout << netNum << endl;
    //int compoNum = p->getComponentNum();
    //cout << compoNum << endl;
    //vector<vector<string>> netListInfo=p->getNetListInfo();         // һ������ȫ����Ϣ����һ��vector<string>��
    //vector<vector<string>> componentInfo=p->getComponentInfo();       // ����������Ƽ�����


    ReadNetListContext * p= new ReadNetListContext(type, dir);
    ReadNetList * p0 =p->getNetListp();      // ָ�� ������Ӧ����������� �Ļ���ָ��
    int netNum = p0->getNetNum();
    cout << netNum << endl;
    int compoNum = p0->getComponentNum();
    cout << compoNum << endl;
    vector<vector<string>> netListInfo = p0->getNetListInfo();         // һ������ȫ����Ϣ����һ��vector<string>��
    vector<vector<string>> componentInfo = p0->getComponentInfo();       // ����������Ƽ�����
    bool status = p0->outfile_to_txt("C:/Users/10057/Desktop/test2.txt");
    if (!status)
    {
        cout << "д���ı��ļ��ɹ�" << endl;
    }

    //cout << "������Ϣ" << endl;
    //for (unsigned int i = 0; i != componentInfo.size(); ++i)
    //{
    //    cout << "��" << i << "��Ԫ����" << endl;
    //    for (unsigned int j = 0; j != componentInfo[i].size(); ++j)
    //    {
    //        cout << componentInfo[i][j] << " ";
    //    }
    //    cout << endl;
    //}
    //cout << "������Ϣ" << endl;
    //for (unsigned int i = 0; i != netListInfo.size(); ++i)
    //{
    //    cout <<"��"<<i<<"������"<< endl;
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