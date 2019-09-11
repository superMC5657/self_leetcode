/* -*- coding: utf-8 -*-
  !@time: 2019-09-11 12:13
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 16_3sum.cpp
 */
#include <environment.h>


class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        int distance = 0;
        int nums_length = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums_length; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;//跳过重复的;
            }
            int left = i + 1;
            int right = nums_length - 1;
            while (left < right) {
                //后续判断left<right 是因为当前loop 只有初次有left<right,后续left和right已经改变了;
                while (left > i + 1 && nums[left] == nums[left - 1] && left < right) {
                    left++;
                }
                while (right < nums_length - 1 && nums[right] == nums[right + 1] && left < right) {
                    right--;
                }
                if (left < right) {
                    int sum = nums[i] + nums[left] + nums[right];
                    if (distance == 0) { //只是在初始化时才会满足此条件,之后如果distance=0, 则已经return了!
                        distance = target - sum;
                    }
                    distance = abs(target - sum) > abs(distance) ? distance : target - sum;
                    if (sum == target) {
                        return sum;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }

                }
            }
        }
        return target - distance;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

int fun() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);

        int ret = Solution().threeSumClosest(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}