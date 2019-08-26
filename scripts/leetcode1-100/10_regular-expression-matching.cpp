//
// Created by 张研 on 2019-08-19.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string str, string pattern) {
        int len1 = str.size();
        int len2 = pattern.size();
        if (len2 && pattern[0] == '*')
            return false;
        vector<vector<bool>> flag(len1 + 1, vector<bool>(len2 + 1, false));
        flag[0][0] = true;
        for (int i = 1; i <= len2; ++i) {
            if (pattern[i - 1] == '*')
                flag[0][i] = flag[0][i - 1] || flag[0][i - 2];
        }
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if ((pattern[j - 1] == str[i - 1]) || (pattern[j - 1] == '.'))
                    flag[i][j] = flag[i - 1][j - 1];
                else if (pattern[j - 1] == '*') {
                    if ((str[i - 1] == pattern[j - 2]) || (pattern[j - 2] == '.')) {
                        flag[i][j] = (flag[i][j - 2] || flag[i][j - 1] || flag[i - 1][j]);
                    } else {
                        flag[i][j] = flag[i][j - 2];
                    }
                } else {
                    flag[i][j] = false;
                }
            }
        }
        return flag[len1][len2];
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
        getline(cin, line);
        string p = stringToString(line);

        bool ret = Solution().isMatch(s, p);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}