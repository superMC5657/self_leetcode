//
// Created by Administrator on 2019/6/17.
//

#include <iostream>
#include <algorithm>
#include "stdio.h"
#include "vector"
#include "map"

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) { //此处的&作为与c# 同作用的ref 可修改nums本身
        map<int, int> a;//提供一对一的hash 相当于python词典
        vector<int> b(2, -1);//用来承载结果，初始化一个大小为2，值为-1的容器b
        for (int i = 0; i < nums.size(); i++) { //每次a 储存 value:key对 当value符合条件 则去除对应的key 所以time:o(n)
            if (a.count(target - nums[i]) > 0) {
                b[0] = a[target - nums[i]];
                b[1] = i;
                break;
            }
            a[nums[i]] = i;//反过来放入map中，用来获取结果下标
        }
        return b;
    };

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

};

int main() {
    int a[] = {2, 7, 11, 15};
    int target = 9;
    vector<int> nums(a, a + sizeof(a) / sizeof(int));
    Solution *solution = new Solution;
    vector<int> b = solution->twoSum(nums, target);
    string nums_str = solution->integerVectorToString(nums);
    cout << nums_str << endl;
    string out = solution->integerVectorToString(b);
    cout << out << endl;
    int m[] = {7, 9, 5, 4, 6, 7, 8, 5, 1, 2, 3, 6};
    target = 17;
    vector<int> nums_2(m, m + sizeof(m) / sizeof(int));
    Solution solution_2 = *new Solution;
    b = solution_2.twoSum(nums_2, target);
    out = solution_2.integerVectorToString(b);
    cout << out << endl;
    return 0;
}
