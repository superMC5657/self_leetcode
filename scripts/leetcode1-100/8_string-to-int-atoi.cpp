/* -*- coding: utf-8 -*-
  !@time: 2019-07-29 18:55
  !@author: superMC @email: 18758266469@163.com
  !@fileName: string_to_int_atoi.c
 */

#include "iostream"

using namespace std;

class Solution {
public:
    int myAtoi(string str);
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() - 1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i + 1];
            switch (nextChar) {
                case '\"':
                    result.push_back('\"');
                    break;
                case '/' :
                    result.push_back('/');
                    break;
                case '\\':
                    result.push_back('\\');
                    break;
                case 'b' :
                    result.push_back('\b');
                    break;
                case 'f' :
                    result.push_back('\f');
                    break;
                case 'r' :
                    result.push_back('\r');
                    break;
                case 'n' :
                    result.push_back('\n');
                    break;
                case 't' :
                    result.push_back('\t');
                    break;
                default:
                    break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string str = stringToString(line);

        int ret = Solution().myAtoi(str);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

int Solution::myAtoi(string str) {
    int i = 0;//位置
    long long res = 0;//输出结果
    int bol = 1;//符号
    while (i < str.size() && str[i] == ' ')++i;//找到第一个非空格的字符
    if (i == str.size())return 0;
    if (str[i] == '-') {
        bol = -1;
        ++i;
    }//运算符正负号
    else if (str[i] == '+') {
        bol = 1;
        ++i;
    }
    while (i < str.size() && str[i] >= '0' && str[i] <= '9') {
        res = res * 10 + str[i++] - '0';
        if (res >= 2147483648) {
            if (bol == 1)return INT_MAX;
            else return INT_MIN;
        }
    }
    return res * bol;
}