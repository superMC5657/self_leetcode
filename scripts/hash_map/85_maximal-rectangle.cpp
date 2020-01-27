/* -*- coding: utf-8 -*-
  !@time: 2019-10-17 23:50
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 85_maximal.cpp
 */
#include <environment.h>
#include <function.hpp>


class solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        if (!matrix.size()) return 0;
        vector<int> dp(matrix[0].size(), 0);//dp用于记录以某一层为底，与之前的所有上层可以形成的连续高度
        int maxArea = 0;
        /*
        循环中调用amxRectangleArea()算法，
        用于找到在一层中结点matrix[i][j]完整包含dp[j]高度的最大宽度
        面积就等于找到的长 * 宽
        */
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                dp[j] = (matrix[i][j] == '1') ? dp[j] + 1 : 0;
            }
            maxArea = max(maxArea, maxRectangleArea(dp));
        }
        return maxArea;
    }

private:
    //84.柱状图中最大的矩形 的代码，
    //用于找到nums中完整包含当前高度的最长宽度
    int maxRectangleArea(vector<int> &nums) {
        stack<int> s;//单调栈
        nums.push_back(0);//设置一个哨兵，让nums遍历到最后时，获得的柱体高度可让单调栈前面的所有元素出栈
        int maxArea = 0;
        for (int i = 0; i < nums.size(); ++i) {
            while (!s.empty() && nums[i] <= nums[s.top()]) {
                int top = s.top();
                s.pop();
                maxArea = max(maxArea, nums[top] * (s.empty() ? i : i - s.top() - 1));
            }
            s.push(i);
        }
        nums.pop_back();
        return maxArea;
    }
};


int fun() {
    string line;
    while (getline(cin, line)) {
        vector<vector<char>> matrix = stringToVectorVectorChar(line);

        int ret = solution().maximalRectangle(matrix);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
