/* -*- coding: utf-8 -*-
  !@time: 2019-09-17 13:45
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 32_longest.cpp
 */
#include "environment.h"

class Solution {
public:

    int longestValidParentheses(string s) {
        int res = 0;
        int left = 0;
        int mark = 0;
        for (int i = 0; i < s.size(); ++i) {
            int prev_mark = mark;
            mark = max(0, mark + ((s[i] == '(') ? 1 : -1));
            if (mark == 0) {
                if (prev_mark > 0) {
                    res = max(i - left + 1, res);
                } else {
                    left = i + 1;
                }
            }
        }
        mark = 0;
        int right = s.size() - 1;
        for (int i = s.size() - 1; i >= 0; --i) {
            int prev_mark = mark;
            mark = max(0, mark + ((s[i] == ')') ? 1 : -1));
            if (mark == 0) {
                if (prev_mark > 0) {
                    res = max(right - i + 1, res);
                } else {
                    right = i - 1;
                }
            }
        }
        return res;
    }

    int longestValidParentheses_dp(string s) {
        int n = s.size();
        int ans = 0;
        vector<int> dp(n, 0);

        for (int i = 1; i < n; ++i) {
            if (s[i] == '(') {
                dp[i] = 0;
            } else {
                int pre = i - 1 - dp[i - 1];
                if (pre >= 0 && s[pre] == '(') {
                    if (pre > 0) {
                        dp[i] = dp[i - 1] + 2 + dp[pre - 1];
                    } else {
                        dp[i] = dp[i - 1] + 2;
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            ans = max(ans, dp[i]);
        }

        return ans;
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
    while (getline(cin, line)) {
        string s = stringToString(line);

        int ret = Solution().longestValidParentheses_dp(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}