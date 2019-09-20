/* -*- coding: utf-8 -*-
  !@time: 2019-09-19 10:51
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 44_wildcard.cpp
 */
#include <environment.h>
#include <function.hpp>

class Solution {
public:
    //压缩字符串 p 中的 *
    string update(string &p) {
        string res;
        for (int i = 0; i < p.size(); i++)
            if (i > 0 && p[i] == p[i - 1] && p[i] == '*');
            else
                res += p[i];
        return res;
    }

    bool isMatch(string s, string p) {
        if (!s.size() || !p.size()) {
            if (!p.size()) {
                return !s.size();
            }
            p = update(p);
            if (p == "*") {
                return !s.size();
            }
            return false;
        }
        p = update(p);
        //因为第一个被NULL占据;
        vector<vector<int>> dp(p.size() + 1, vector<int>(s.size() + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= p.size(); i++) {
            dp[i][0] = p[i - 1] == '*' ? dp[i - 1][0] : 0;
            for (int j = 1; j <= s.size(); j++) {
                if (p[i - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];

                } else if (p[i - 1] == '?' || p[i - 1] == s[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }

        }
        return dp[p.size()][s.size()];
    }
};

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