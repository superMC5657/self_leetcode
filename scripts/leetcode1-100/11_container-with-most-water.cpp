/* -*- coding: utf-8 -*-
  !@time: 2019-09-10 20:04
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 11_container.cpp
 */

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int left_p = 0;
        int right_p = height.size() - 1;
        int area = 0;
        while (right_p > left_p) {
            int bottom = right_p - left_p;
            if (height[right_p] >= height[left_p]) {
                int new_area = (bottom * height[left_p]);
                area = max(area, new_area);
                left_p++;
            } else {
                int new_area = (bottom * height[right_p]);
                area = max(area, new_area);
                right_p--;
            }
        }
        return area;
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

int fun() {
    string line;
    while (getline(cin, line)) {
        vector<int> height = stringToIntegerVector(line);

        int ret = Solution().maxArea(height);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}