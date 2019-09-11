/* -*- coding: utf-8 -*-
  !@time: 2019-09-11 10:40
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 13_roman.cpp
 */
#include <environment.h>

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> m = {{"I",  1},
                                        {"IV", 3},
                                        {"IX", 8},
                                        {"V",  5},
                                        {"X",  10},
                                        {"XL", 30},
                                        {"XC", 80},
                                        {"L",  50},
                                        {"C",  100},
                                        {"CD", 300},
                                        {"CM", 800},
                                        {"D",  500},
                                        {"M",  1000}};
        int res = m[s.substr(0, 1)];
        for (int i = 1; i < s.size(); i++) {
            string two = s.substr(i - 1, 2);
            string one = s.substr(i, 1);
            res += m[two] ? m[two] : m[one]; //遍历的时候 m[one]在上一次已经加过了!

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

int fun() {
    string line;
    while (getline(std::cin, line)) {
        string s = stringToString(line);

        int ret = Solution().romanToInt(s);

        string out = std::to_string(ret);
        std::cout << out << std::endl;
    }
    return 0;
}