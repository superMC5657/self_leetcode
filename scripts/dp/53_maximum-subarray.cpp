/* -*- coding: utf-8 -*-
  !@time: 2019-09-20 18:42
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 53_maximum.cpp
 */
#include <environment.h>
#include <function.hpp>

class solution {
public:
    int maxSubArray(vector<int> &nums) {
        int ans = nums[0];
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            ans = max(sum, ans);
            if (sum < 0) {
                sum = 0;
            }
        }
        return ans;
    }
};

int fun() {
    string line;
    while (getline(cin, line)) {
        vector<int> arr = stringToIntegerVector(line);

        int ret = solution().maxSubArray(arr);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}