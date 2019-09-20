/* -*- coding: utf-8 -*-
  !@time: 2019-09-19 19:03
  !@author: superMC @email: 18758266469@163.com
  !@fileName: maximum.cpp
 */
#include "environment.h"

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        typedef unordered_map<char, double> umap;
        int res = INT32_MAX;
        umap record = {{'b', 0.0},
                       {'a', 0.0},
                       {'l', 0.0},
                       {'o', 0.0},
                       {'n', 0.0},
        };
        for (char c : text) {
            switch (c) {
                case 'b':
                    record[c] += 1.0;
                    break;
                case 'a':
                    record[c] += 1.0;
                    break;
                case 'l':
                    record[c] += 0.5;
                    break;
                case 'o':
                    record[c] += 0.5;
                    break;
                case 'n':
                    record[c] += 1.0;
                    break;
                default:
                    break;
            }
        }
        for (auto &x : record) {
            res = min(res, (int) x.second);
        }
        return res;
    }
};

int fun() {
    string text = "ballon";
    int res = Solution().maxNumberOfBalloons(text);
    cout << res << endl;
    return 0;
}