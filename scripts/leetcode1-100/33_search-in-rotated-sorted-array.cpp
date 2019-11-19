/* -*- coding: utf-8 -*-
  !@time: 2019-11-19 07:55
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 33_search.cpp
 */
#include <environment.h>
#include <function.hpp>

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo == hi && nums[lo] == target ? lo : -1;
    }
};

int fun() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        string targetStr;
        getline(cin, targetStr);
        int target = stringToInteger(targetStr);
        int ret = Solution().search(nums, target);
        cout << ret << endl;
    }
    return 0;
}
