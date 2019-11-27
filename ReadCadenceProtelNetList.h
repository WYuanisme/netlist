#pragma once
#include "ReadNetList.h"
class ReadCadenceProtelNetList :
    public ReadNetList
{
private:
    unsigned int netNum;                                 // ���������
    unsigned int componentNum;                           // ���������
    vector<vector<string>> netListInfo;         // һ������ȫ����Ϣ����һ��vector<string>��
    vector<vector<string>> componentInfo;       // ����������Ƽ�����

public:
    ReadCadenceProtelNetList() = default;
    ReadCadenceProtelNetList(string netListDir);
    virtual ~ReadCadenceProtelNetList();

    virtual unsigned int getNetNum();
    virtual unsigned int getComponentNum();
    virtual vector<vector<string>> getNetListInfo();
    virtual vector<vector<string>> getComponentInfo();
    virtual bool outfile_to_txt(const string &file_path_name);

};

