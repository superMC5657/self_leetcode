/* -*- coding: utf-8 -*-
  !@time: 2019-07-29 19:19
  !@author: superMC @email: 18758266469@163.com
  !@fileName: valid.c
 */
#include "iostream"

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        // regex r("\\s*[+-]?(\\d+\\.?\\d*|\\.\\d+)(e[+-]?\\d+)?\\s*$");
        int i = s.find_first_not_of(' ');
        int d1 = 0, dot = 0, d2 = 0, e = 0, d3 = 0;
        if (s[i] == '+' || s[i] == '-') ++i;
        for (; i < s.length() && isdigit(s[i]); d1 = ++i);
        if (i < s.length() && s[i] == '.') dot = ++i;
        for (; i < s.length() && isdigit(s[i]); d2 = ++i);
        if (dot && !d1 && !d2) return false;
        if (i < s.length() && (d1 || d2) && s[i] == 'e') e = ++i;
        if (i < s.length() && e && (s[i] == '+' | s[i] == '-')) ++i;
        for (; i < s.length() && isdigit(s[i]); d3 = ++i);
        if (e && (!(d1 || d2) || !d3)) return false;
        for (; i < s.length() && s[i] == ' '; ++i);
        return i == s.length();
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int fun() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);

        bool ret = Solution().isNumber(s);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}