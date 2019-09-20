/* -*- coding: utf-8 -*-
  !@time: 2019-09-19 20:00
  !@author: superMC @email: 18758266469@163.com
  !@fileName: k.cpp
 */
#include "environment.h"
#include "function.hpp"

class Solution {
    int mod = 1000000007;
public:
    int kConcatenationMaxSum(vector<int> &arr, int k) {
        long long single_sum = 0;
        for (int i = 0; i < arr.size(); ++i) {
            single_sum += arr[i];
        }
        vector<int> double_arr(2 * arr.size());
        double_arr.insert(double_arr.end(), arr.begin(), arr.end());
        double_arr.insert(double_arr.end(), arr.begin(), arr.end());
        if (single_sum > 0) {
            //求两个arr 组合在一起的sum + k-2 single_sum
            return maxSubSequence(double_arr) + (k - 2) * single_sum%mod;
        } else {
            //求两个arr 组合在一起的sum or 一个arr的最大值

            return max(maxSubSequence(arr), maxSubSequence(double_arr))%mod;
        }
    }

    int maxSubSequence(vector<int> &arr) {
        int ans = arr[0];
        int sum = 0;
        for (int i = 0; i < arr.size(); ++i) {
            sum += arr[i];
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
        getline(cin, line);
        int k = stringToInteger(line);

        int ret = Solution().kConcatenationMaxSum(arr, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}