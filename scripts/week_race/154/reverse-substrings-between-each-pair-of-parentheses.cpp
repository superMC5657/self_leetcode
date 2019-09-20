/* -*- coding: utf-8 -*-
  !@time: 2019-09-19 19:49
  !@author: superMC @email: 18758266469@163.com
  !@fileName: reverse.cpp
 */
#include "environment.h"

class Solution {
public:
    string reverseParentheses(string s) {
        if (s == "") {
            return "";
        }
        stack<string> stack_s;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stack_s.push("");
            } else if (s[i] == ')') {
                string tmp = stack_s.top();
                stack_s.pop();
                std::reverse(tmp.begin(), tmp.end());
                if (!stack_s.empty()) {
                    stack_s.top() = stack_s.top() + tmp;
                } else {
                    stack_s.push(tmp);
                }
            } else {
                if (stack_s.empty()) {
                    stack_s.push("");
                }
                stack_s.top() = stack_s.top() + s[i];
            }
        }
        return stack_s.top();
    }

    string reverseParentheses_template(string s) {
        stack<int> st;
        string res;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int top = st.top();
                st.pop();
                reverse(s.begin() + top + 1, s.begin() + i);
            }
        }
        for (auto it: s) {
            if (it != '(' && it != ')') {
                res.push_back(it);
            }
        }
        return res;
    }
};

int fun() {
    string s = "(abcd)";
    string ret = Solution().reverseParentheses(s);
    cout << ret << endl;
    return 0;
}