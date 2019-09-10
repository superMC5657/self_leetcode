/* -*- coding: utf-8 -*-
  !@time: 2019-09-11 00:44
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 12_integer.cpp
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> strs = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    string intToRoman(int num) {

        string res;
        for (int i = 0; i < values.size(); i++) {
            while (num >= values[i]) {
                res += strs[i];
                num -= values[i];
            }
        }
        return res;

    }

};

int stringToInteger(string input) {
    return stoi(input);
}

int fun() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);

        string ret = Solution().intToRoman(num);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}