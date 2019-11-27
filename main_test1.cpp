//--------------------------------------------------------------------
// Code by WangYuan; Date:2019/8/30
// Input：网表文件地址+文件名
// Output：器件信息、网络信息
//--------------------------------------------------------------------


#if 0
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <vector>
#include <string>
#include <list>

using namespace std;

int main()
{
    // 一个网络全部信息存在一个vector<string>中
    vector<vector<string>> netListInfo;
    // 存放器件名称及类型
    vector<vector<string>> componentInfo;

    // 实现把网表文件一次全部读入到string里：
    // 把网表文件读入文件流对象
    // 把文件流对象的内容给string流
    // 把string流对象所保存的内容的拷贝赋给netListFileContent
    ifstream inFile_NetList("C:/Users/10057/Desktop/BStest.NET");
    //ifstream inFile_NetList("C:/Users/10057/Desktop/STM32.NET");
    ostringstream temp;
    temp << inFile_NetList.rdbuf();
    string netListFileContent = temp.str();

    // 定义正则表达式
    regex bracketBeg("\\(");
    //   regex bracketEnd("\\)");
    regex squareBracketBeg("\\[");
    //regex squareBracketEnd("\\]");
    // 结点：网络名-引脚
 //regex netInfo("^[[:alpha:]]{1,2}[[:digit:]]{1,2}-[[:digit:]]{1,2}");


 // 提取器件信息
    for (sregex_iterator it(netListFileContent.begin(), netListFileContent.end(), squareBracketBeg), end_it; it != end_it; ++it)
    {
        // 把 [ 后的200个char放入temp中
        auto pos = it->suffix().str().length();
        pos = pos > 200 ? 200 : pos;
        string temp = it->suffix().str().substr(1, pos);
        string::iterator it_str = temp.begin();

        // 如果迭代器it还没指向 ] ，就说明这个器件信息还没读完
        vector<string> temp_vector;
        int i = 0;
        while (*it_str != ']')
        {
            string temp_string;
            while (*it_str != '\n')
            {
                // 第0行是器件名，最后一行（第二行）是产品类型
                if ((i == 0) | (i == 2))
                {
                    char temp_char = *it_str;
                    temp_string = temp_string + temp_char;
                }
                ++it_str;

            }
            // 如果是0、2行，就存下来
            if ((i == 0) | (i == 2))
            {
                temp_vector.push_back(temp_string);
            }
            // 跳出循环，此时 *it_str = '\n'，需要让迭代器指向下一个char
            ++it_str;
            // 行数+1
            ++i;
        }
        // 第i个器件信息已存完
        componentInfo.push_back(temp_vector);
        // 让迭代器指向temp末尾，免得它乱跑
        it_str = temp.end();
    }

    // 输出器件信息
    for (int i = 0; i != componentInfo.size(); ++i)
    {
        for (int j = 0; j != componentInfo[i].size(); ++j)
        {
            cout << componentInfo[i][j] << " ";
        }
        cout << endl;
    }



    // 提取网络信息
    for (sregex_iterator it(netListFileContent.begin(), netListFileContent.end(), bracketBeg), end_it; it != end_it; ++it)
    {
        // 把 ( 后的500个char放入temp中
        auto pos = it->suffix().str().length();
        pos = pos > 500 ? 500 : pos;
        string temp = it->suffix().str().substr(1, pos);
        string::iterator it_str = temp.begin();

        // 如果迭代器it还没指向 ) ，就说明这个网络的结点还没读完
        vector<string> temp_vector;
        while (*it_str != ')')
        {
            // 第0行是网络名，后面一行是一个结点
            string temp_string;
            while (*it_str != '\n')
            {
                char temp_char = *it_str;
                temp_string = temp_string + temp_char;
                ++it_str;

            }
            temp_vector.push_back(temp_string);
            // 跳出循环，此时 *it_str = '\n'，需要让迭代器指向下一个char
            ++it_str;
        }
        // 第i个网络信息已存完
        netListInfo.push_back(temp_vector);
        // 让迭代器指向temp末尾，免得它乱跑
        it_str = temp.end();
    }

    // 输出
    for (int i = 0; i != netListInfo.size(); ++i)
    {
        for (int j = 0; j != netListInfo[i].size(); ++j)
        {
            cout << netListInfo[i][j] << " ";
        }
        cout << endl;
    }


    system("pause");
}



#endif