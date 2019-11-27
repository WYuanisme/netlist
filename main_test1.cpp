//--------------------------------------------------------------------
// Code by WangYuan; Date:2019/8/30
// Input�������ļ���ַ+�ļ���
// Output��������Ϣ��������Ϣ
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
    // һ������ȫ����Ϣ����һ��vector<string>��
    vector<vector<string>> netListInfo;
    // ����������Ƽ�����
    vector<vector<string>> componentInfo;

    // ʵ�ְ������ļ�һ��ȫ�����뵽string�
    // �������ļ������ļ�������
    // ���ļ�����������ݸ�string��
    // ��string����������������ݵĿ�������netListFileContent
    ifstream inFile_NetList("C:/Users/10057/Desktop/BStest.NET");
    //ifstream inFile_NetList("C:/Users/10057/Desktop/STM32.NET");
    ostringstream temp;
    temp << inFile_NetList.rdbuf();
    string netListFileContent = temp.str();

    // ����������ʽ
    regex bracketBeg("\\(");
    //   regex bracketEnd("\\)");
    regex squareBracketBeg("\\[");
    //regex squareBracketEnd("\\]");
    // ��㣺������-����
 //regex netInfo("^[[:alpha:]]{1,2}[[:digit:]]{1,2}-[[:digit:]]{1,2}");


 // ��ȡ������Ϣ
    for (sregex_iterator it(netListFileContent.begin(), netListFileContent.end(), squareBracketBeg), end_it; it != end_it; ++it)
    {
        // �� [ ���200��char����temp��
        auto pos = it->suffix().str().length();
        pos = pos > 200 ? 200 : pos;
        string temp = it->suffix().str().substr(1, pos);
        string::iterator it_str = temp.begin();

        // ���������it��ûָ�� ] ����˵�����������Ϣ��û����
        vector<string> temp_vector;
        int i = 0;
        while (*it_str != ']')
        {
            string temp_string;
            while (*it_str != '\n')
            {
                // ��0���������������һ�У��ڶ��У��ǲ�Ʒ����
                if ((i == 0) | (i == 2))
                {
                    char temp_char = *it_str;
                    temp_string = temp_string + temp_char;
                }
                ++it_str;

            }
            // �����0��2�У��ʹ�����
            if ((i == 0) | (i == 2))
            {
                temp_vector.push_back(temp_string);
            }
            // ����ѭ������ʱ *it_str = '\n'����Ҫ�õ�����ָ����һ��char
            ++it_str;
            // ����+1
            ++i;
        }
        // ��i��������Ϣ�Ѵ���
        componentInfo.push_back(temp_vector);
        // �õ�����ָ��tempĩβ�����������
        it_str = temp.end();
    }

    // ���������Ϣ
    for (int i = 0; i != componentInfo.size(); ++i)
    {
        for (int j = 0; j != componentInfo[i].size(); ++j)
        {
            cout << componentInfo[i][j] << " ";
        }
        cout << endl;
    }



    // ��ȡ������Ϣ
    for (sregex_iterator it(netListFileContent.begin(), netListFileContent.end(), bracketBeg), end_it; it != end_it; ++it)
    {
        // �� ( ���500��char����temp��
        auto pos = it->suffix().str().length();
        pos = pos > 500 ? 500 : pos;
        string temp = it->suffix().str().substr(1, pos);
        string::iterator it_str = temp.begin();

        // ���������it��ûָ�� ) ����˵���������Ľ�㻹û����
        vector<string> temp_vector;
        while (*it_str != ')')
        {
            // ��0����������������һ����һ�����
            string temp_string;
            while (*it_str != '\n')
            {
                char temp_char = *it_str;
                temp_string = temp_string + temp_char;
                ++it_str;

            }
            temp_vector.push_back(temp_string);
            // ����ѭ������ʱ *it_str = '\n'����Ҫ�õ�����ָ����һ��char
            ++it_str;
        }
        // ��i��������Ϣ�Ѵ���
        netListInfo.push_back(temp_vector);
        // �õ�����ָ��tempĩβ�����������
        it_str = temp.end();
    }

    // ���
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