/* -*- coding: utf-8 -*-
  !@time: 2019-09-11 11:07
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 14_longest.cpp
 */
#include <environment.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {

        int lenVec = strs.size();
        if (lenVec == 0)
            return "";// 如果vector中没有string，返回空串
        if (lenVec == 1)
            return strs.at(0);//如果vector中有一个string，直接返回该串

        int j = 0;//记录最大公共前缀长度
        while (1) {
            for (int i = 0; i < lenVec; i++) {
                if (j >= strs.at(i).size())
                    return strs.at(i).substr(0, j);//如果遇到字串结束，返回已找到的前缀

                char c = strs.at(0).at(j);
                if (c != strs.at(i).at(j))
                    return strs.at(i).substr(0, j);//如果遇到字串中字母不相等，返回已找到的前缀
            }
            j++;
        }
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<string> stringToStringVector(string input) {
    vector<string> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(item);
    }
    return output;
}

int fun() {
    string line;
    while (getline(cin, line)) {
        vector<string> input = stringToStringVector(line);
        string out = Solution().longestCommonPrefix(input);
        cout << out << endl;
    }
    return 0;
}