/* -*- coding: utf-8 -*-
  !@time: 2019/6/20 18:55
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 3sum.cpp
 */
#include <environment.h>


class Solution {
public:
    vector<vector<int>> threeSum_collisionPointer(vector<int> &nums) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        if (nums.empty() || nums.front() > 0 || nums.back() < 0)
            return {};

        for (int i = 0; i < nums.size(); i++) {
            int fix = nums[i];
            if (fix > 0) break;
            if (i > 0 && fix == nums[i - 1]) continue;
            //对撞指针
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                if (nums[l] + nums[r] == -fix) {
                    if (l == i + 1 || r == nums.size() - 1) {
                        res.push_back(vector<int>{nums[i], nums[l], nums[r]});
                        l++;
                        r--;
                    } else if (nums[l] == nums[l - 1])
                        l++;
                    else if (nums[r] == nums[r + 1])
                        r--;
                    else {
                        res.push_back(vector<int>{nums[i], nums[l], nums[r]});
                        l++;
                        r--;
                    }

                } else if (nums[l] + nums[r] < -fix)
                    l++;
                else
                    r--;
            }
        }
        return res;
    }

    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int >> result;
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
                    if (sum == 0) {
                        vector<int> t;
                        t.push_back(nums[i]);
                        t.push_back(nums[left]);
                        t.push_back(nums[right]);
                        result.push_back(t);
                        left++;
                        right--;
                    } else if (sum < 0) {
                        left++;
                    } else {
                        right--;
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


int fun() {
    string line;
    while (getline(cin, line)) {
        //line = "[2,-3,0,-2,-5,-5,-4,1,2,-2,2,0,2,-4]";
        vector<int> nums = stringToIntegerVector(line);
        vector<vector<int>> ret = Solution().threeSum(nums);
        string res = "";
        for (const vector<int> &item : ret) {
            res += integerVectorToString(item);
            res += "\n";
        }
        cout << res << endl;
    }
    return 0;
}