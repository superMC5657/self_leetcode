/* -*- coding: utf-8 -*-
  !@time: 2019-09-25 01:50
  !@author: superMC @email: 18758266469@163.com
  !@fileName: ugly.cpp
 */
#include <environment.h>

class Solution {
    typedef long long ll;
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        int a_iter = 1, b_iter = 1, c_iter = 1;
        int uglyNum;
        ll a_num, b_num, c_num;
        a_num = (ll) a * a_iter;
        b_num = (ll) b * b_iter;
        c_num = (ll) c * c_iter;
        while (n > 0) {
            if (a_num <= b_num && a_num <= c_num) {
                uglyNum = (int) a_num;
                if (a_num == b_num) {
                    b_iter++;
                    b_num = (ll) b * b_iter;
                }
                if (a_num == c_num) {
                    c_iter++;
                    c_num = (ll) c * c_iter;
                }
                a_iter++;
                a_num = (ll) a * a_iter;
            } else if (b_num < a_num && b_num <= c_num) {
                if (b_num == c_num) {
                    c_iter++;
                    c_num = (ll) c * c_iter;
                }
                uglyNum = (int) b_num;
                b_iter++;
                b_num = (ll) b * b_iter;
            } else {
                uglyNum = (int) c_num;
                c_iter++;
                c_num = (ll) c * c_iter;
            }
            n--;
        }
        return uglyNum;
    }

    int nthUglyNumber_template(int n, int a, int b, int c) {
        int left = 0, right = INT_MAX, result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (count(mid, a, b, c) >= n) { // find mid as small as possible that count == n
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }

private:

    ll gcd(ll a, ll b) {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

    ll lcm(ll a, ll b) {
        return a * b / gcd(a, b);
    }

    int count(ll num, ll a, ll b, ll c) {
        return (int) (num / a + num / b + num / c
                      - num / lcm(a, b)
                      - num / lcm(b, c)
                      - num / lcm(a, c)
                      + num / (lcm(a, lcm(b, c))));
    }
};

int fun() {
    int n = 3, a = 2, b = 3, c = 5;
    int ret = Solution().nthUglyNumber(n, a, b, c);
    string out = to_string(ret);
    cout << out << endl;
    return 0;
}