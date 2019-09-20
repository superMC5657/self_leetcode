/* -*- coding: utf-8 -*-
  !@time: 2019-09-19 00:29
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 101_symmetric.cpp
 */
#include <environment.h>
#include "function.hpp"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        return fun(root->left, root->right);

    }

    bool fun(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right == nullptr) {
            return true;
        }
        if (left == nullptr || right == nullptr) {
            return false;
        }
        return left->val == right->val && fun(left->left, right->right) && fun(left->right, right->left);
    }
};

int fun() {
    string line;
    while (getline(cin, line)) {
        TreeNode *root = stringToTreeNode(line);

        bool ret = Solution().isSymmetric(root);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}