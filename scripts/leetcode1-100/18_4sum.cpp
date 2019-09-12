/* -*- coding: utf-8 -*-
  !@time: 2019-09-12 13:06
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 18_4sum.cpp
 */

#include <environment.h>

class Solution {
public:

    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int >> result;
        int nums_length = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums_length - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;//跳过重复的;
            }
            for (int j = i + 1; j < nums_length - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;//跳过重复的;
                }
                int left = j + 1;
                int right = nums_length - 1;
                while (left < right) {
                    //后续判断left<right 是因为当前loop 只有初次有left<right,后续left和right已经改变了;
                    while (left > j + 1 && nums[left] == nums[left - 1] && left < right) {
                        left++;
                    }
                    while (right < nums_length - 1 && nums[right] == nums[right + 1] && left < right) {
                        right--;
                    }
                    if (left < right) {
                        int sum = nums[i] + nums[j] + nums[left] + nums[right];
                        if (sum == target) {
                            vector<int> t;
                            t.push_back(nums[i]);
                            t.push_back(nums[j]);
                            t.push_back(nums[left]);
                            t.push_back(nums[right]);
                            result.push_back(t);
                            left++;
                            right--;
                        } else if (sum < target) {
                            left++;
                        } else {
                            right--;
                        }
                    }
                }
            }
        }
        return result;
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

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for (int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int stringToInteger(string input) {
    return stoi(input);
}

int fun() {
    string line;
    while (getline(cin, line)) {
        //line = "[2,-3,0,-2,-5,-5,-4,1,2,-2,2,0,2,-4]";
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        vector<vector<int>> ret = Solution().fourSum(nums, target);
        string res = "";
        for (const vector<int> &item : ret) {
            res += integerVectorToString(item);
            res += "\n";
        }
        cout << res << endl;
    }
    return 0;
}