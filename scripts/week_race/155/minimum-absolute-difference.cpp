/* -*- coding: utf-8 -*-
  !@time: 2019-09-25 01:18
  !@author: superMC @email: 18758266469@163.com
  !@fileName: minimum.cpp
 */
#include <environment.h>
#include <function.hpp>


class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr) {
        vector<vector<int>> ret;
        int arr_length = arr.size();
        sort(arr.begin(), arr.end());
        int nearest_distance = INT32_MAX;
        for (int i = 0; i < arr_length - 1; ++i) {
            int distance = arr[i + 1] - arr[i];
            nearest_distance = distance < nearest_distance ? distance : nearest_distance;
        }
        for (int j = 0; j < arr_length - 1; ++j) {
            if (arr[j + 1] - arr[j] == nearest_distance) {
                vector<int> tmp(2);
                tmp[0] = arr[j];
                tmp[1] = arr[j + 1];
                ret.push_back(tmp);
            }
        }
        return ret;
    }
};

int fun() {
    string s = "[1,3,6,10,15]";
    vector<int> arr = stringToIntegerVector(s);
    vector<vector<int >> ret = Solution().minimumAbsDifference(arr);
    string res = integerVectorVectorToString(ret);
    cout << res << endl;
    return 0;
}