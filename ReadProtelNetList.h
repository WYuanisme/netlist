#pragma once
#include "ReadNetList.h"

#include <vector>
#include <string>

using std::vector;
using std::string;

class ReadProtelNetList :
    public ReadNetList
{
private:
    unsigned int netNum;                                 // 存放网络数
    unsigned int componentNum;                           // 存放器件数
    vector<vector<string>> netListInfo;         // 一个网络全部信息存在一个vector<string>中
    vector<vector<string>> componentInfo;       // 存放器件名称及类型

public:
    ReadProtelNetList()= default;
    ReadProtelNetList(string netListDir);
    virtual ~ReadProtelNetList();

    virtual unsigned int getNetNum();
    virtual unsigned int getComponentNum();
    virtual vector<vector<string>> getNetListInfo();
    virtual vector<vector<string>> getComponentInfo();
    virtual bool outfile_to_txt(const string &file_path_name);
};

