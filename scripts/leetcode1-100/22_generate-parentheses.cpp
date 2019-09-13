/* -*- coding: utf-8 -*-
  !@time: 2019-09-13 01:40
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 22_generate.cpp
 */
#include <environment.h>

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n <= 0) {
            return {};
        } else if (n == 1) {
            return {"()"};
        } else {
            vector<vector<string>> dp(n + 1);
            dp[0] = {""};
            dp[1] = {"()"};
            for (int i = 2; i <= n; i++) {
                for (int j = 0; j < i; j++) {
                    for (string p : dp[j])
                        for (string q : dp[i - j - 1]) { // 保证()的数量为i;
                            string str = "(" + p + ")" + q;
                            dp[i].push_back(str);
                        }
                }
            }
            return dp[n];
        }
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string stringVectorToString(const vector<string> &list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for (int i = 0; i < length; i++) {
        result += list[i] + ',';
    }
    return "[" + result.substr(0, result.length() - 1) + "]";
}


int fun() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);

        vector<string> ret = Solution().generateParenthesis(num);

        string out = stringVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}