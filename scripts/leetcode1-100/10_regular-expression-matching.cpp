//
// Created by 张研 on 2019-08-19.
//
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool> > dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (j > 1 && p[j - 1] == '*') {
                    if (i > 0) {
                        dp[i][j] = dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.');
                    }
                    dp[i][j] = dp[i][j] || dp[i][j - 2];
                } else if (i > 0) {
                    dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[m][n];
    }

    bool isMatch_Recursive(string str, string pattern) {
        int pattern_length = pattern.size();
        int str_length = str.size();
        if (0 == pattern_length) {
            return str_length == 0;
        }

        bool first_match = false;
        if (str_length > 0 && (pattern[0] == str[0] || pattern[0] == '.')) {
            first_match = true;
        }
        if (pattern_length >= 2 && pattern[1] == '*') {
            return isMatch_Recursive(str, pattern.substr(2, static_cast<unsigned int>(pattern_length - 1))) ||
                   (first_match &&
                    isMatch_Recursive(str.substr(1, static_cast<unsigned int>(str_length - 1)), pattern));
        } else {
            return first_match && isMatch_Recursive(str.substr(1, static_cast<unsigned int>(str_length - 1)),
                                                    pattern.substr(1, static_cast<unsigned int>(pattern_length - 1)));

        }
    }

    bool isMatch_DP(const string &str, const string &pattern) {
        int parttern_length = pattern.size();
        int str_length = str.size();
        if (0 == parttern_length) {
            return str_length == 0;
        }
        vector<vector<int >> flag(static_cast<unsigned int>(str_length + 1), vector<int>(
                static_cast<unsigned int>(parttern_length + 1), 0));
        flag[0][0] = 1;
        for (int i = 0; i <= str_length; i++) {
            for (int j = 1; j <= parttern_length; j++) {
                if (j > 1 && pattern[j - 1] == '*') {
                    if (i > 0) {
                        flag[i][j] = flag[i - 1][j] && (str[i - 1] == pattern[j - 2] || pattern[j - 2] == '.');
                    }
                    flag[i][j] = flag[i][j] || flag[i][j - 2];
                } else if (i > 0) {
                    flag[i][j] = flag[i - 1][j - 1] && (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '.');
                }
            }
        }
        return flag[str_length][parttern_length];
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

        bool ret = Solution().isMatch_DP(s, p);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}