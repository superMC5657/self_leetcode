/* -*- coding: utf-8 -*-
  !@time: 2019/10/19 17:04
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 37_sudoku.cpp
 */
#include <environment.h>
#include <function.hpp>

class Solution {
public:
    static void solveSudoku(vector<vector<char>> &board) {

    }
};

int fun() {
    string line;
    while (getline(cin, line)) {
        vector<vector<char>> matrix = stringToVectorVectorChar(line);
        Solution::solveSudoku(matrix);
        string out = charVectorVectorToString(matrix);
        cout << out << endl;
    }
    return 0;
}
