/* -*- coding: utf-8 -*-
  !@time: 2019-09-16 10:35
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 26_remove.cpp
 */
#include <environment.h>
#include "function.hpp"

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int i = 0;
        for (int j = 1; j < nums.size(); ++j) {
            if (nums[i] != nums[j]) {
                nums[++i] = nums[j];
            }
        }
        return i + 1;
    }
};


int fun() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        int ret = Solution().removeDuplicates(nums);

        string out = integerVectorToString(nums, ret);
        cout << out << endl;
    }
    return 0;
}