/* -*- coding: utf-8 -*-
  !@time: 2019-09-16 10:59
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 29_divide.cpp
 */
#include <environment.h>
#include "function.hpp"

class Solution {
public:
    int divide(int dividend, int divisor) {

        if (divisor == dividend) return 1;
        if (dividend == 0) return 0;
        if (dividend > INT_MAX || divisor > INT_MAX || dividend < INT_MIN || divisor < INT_MIN ||
            (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        if (divisor == 1) return dividend;
        if (divisor == -1) return -dividend;
        if (divisor == INT_MIN) return 0;


        int flag;
        long sum = 1;
        long num = 1;

        if ((dividend > 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
            flag = divisor > 0 ? 1 : -1;
            divisor = abs(divisor);
            if (divisor > dividend) return 0;
            long temp = divisor;
            while (dividend - temp >= divisor) {
                while (dividend - temp >= divisor) {
                    sum = sum + num;
                    dividend = dividend - temp;
                    temp = temp << 1;
                    num = num << 1;
                }
                temp = divisor;
                num = 1;
            }
            return flag > 0 ? sum : -sum;
        } else {
            flag = divisor > 0 ? -1 : 1;
            divisor = -abs(divisor);
            if (divisor < dividend) return 0;
            long temp = -divisor;
            while (dividend + temp <= divisor) {
                while (dividend + temp <= divisor) {
                    sum = sum + num;
                    dividend = dividend + temp;
                    temp = temp << 1;
                    num = num << 1;
                }
                temp = -divisor;
                num = 1;
            }
            return flag > 0 ? sum : -sum;

        }

    }
};


int fun() {
    string line;
    while (getline(cin, line)) {
        int dividend = stringToInteger(line);
        getline(cin, line);
        int divisor = stringToInteger(line);

        int ret = Solution().divide(dividend, divisor);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}