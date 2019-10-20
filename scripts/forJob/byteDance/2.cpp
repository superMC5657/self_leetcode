/* -*- coding: utf-8 -*-
  !@time: 2019-10-20 19:15
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 2.cpp
 */
#include <iostream>

using namespace std;
typedef long long ll;

int fun() {
    int n;
    while (cin >> n) {
        ll up_t = 1;
        ll down_t = 0;
        for (ll i = 0; i < n; i++) {
            ll tmp = (ll) (up_t * 3 + down_t);
            down_t = (ll) (up_t + down_t * 3);
            up_t = tmp;
        }
        cout << up_t % 1000000007 << endl;
    }
    return 0;
}