/* -*- coding: utf-8 -*-
  !@time: 2019-09-13 01:40
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 22_generate.cpp
 */
#include <environment.h>

class Solution {
public:
    vector<string> generateParenthesis(int n) {


    }
};

int stringToInteger(string input) {
    return stoi(input);
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
        int num = stringToInteger(line);

        vector<string> ret = Solution().generateParenthesis(num);

        string out = stringVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}