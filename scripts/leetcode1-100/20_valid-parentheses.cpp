/* -*- coding: utf-8 -*-
  !@time: 2019-09-12 15:54
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 20_valid.cpp
 */
#include <environment.h>

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack_ct;
        //for (char c : s) slow!!
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stack_ct.push(s[i]);
            } else {
                if (stack_ct.empty()) {
                    return false;
                } else {
                    if (s[i] - stack_ct.top() == 1 || s[i] - stack_ct.top() == 2) {
                        stack_ct.pop();
                    } else {
                        return false;
                    }
                }
            }
        }
        return stack_ct.empty();
    }

    bool isValid_tempalte(string s) {
        stack<char> st;
        for (char c : s) {
            if (st.empty() && (c == ')' || c == '}' || c == ']'))
                return false;    //栈空，遇到右边的括号，直接返回false
            if (c == ')' || c == '}' || c == ']')  //遇到右边的括号，判断栈顶是否
            {                                 //是对应的左边的括号。
                if (c - st.top() == 1 || c - st.top() == 2)
                    st.pop();   //对应的话，栈顶元素退栈。
                else
                    return false;  //不对应的话，直接返回false。
            } else
                st.push(c);   //遇到左边的括号，进栈。
        }
        return st.empty();  //栈空，说明括号都匹配了。
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

        bool ret = Solution().isValid(s);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}