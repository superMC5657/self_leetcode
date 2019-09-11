/* -*- coding: utf-8 -*-
  !@time: 2019-09-11 20:28
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 17_letter.cpp
 */
#include <environment.h>

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> telephone_dict{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        if (digits.empty()) {
            return res;
        }
        res.emplace_back(""); //确保开始时有东西可以排列组合;
        for (char num : digits) {
            int index = num - '2'; //ascii减法得num;
            int res_length = res.size();
            for (int i = 0; i < res_length; i++) { //与上一个res进行排列组合;
                for (char c : telephone_dict[index]) {
                    res.push_back(res[i] + c);
                }
            }
            res.erase(res.begin(), res.begin() + res_length);//擦除无用的;
        }
        return res;
    }
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

string stringVectorToString(vector<string> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for (string str : list) {
        result += str + ',';
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}


int fun() {
    string line;
    while (getline(cin, line)) {
        string str = stringToString(line);

        vector<string> ret = Solution().letterCombinations(str);

        string out = stringVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}