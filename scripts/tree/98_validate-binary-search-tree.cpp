/* -*- coding: utf-8 -*-
  !@time: 2019-09-26 10:33
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 98_validate.cpp
 */
#include <environment.h>
#include <function.hpp>

class Solution {
private:
    void inOrder(struct TreeNode *root, int arr[], int *len) {
        if (root != NULL) {
            inOrder(root->left, arr, len);
            arr[(*len)++] = root->val;

            inOrder(root->right, arr, len);
        }
    }

public:
    bool isValidBST(struct TreeNode *root) {
        int arr[10000];
        int len = 0;
        inOrder(root, arr, &len);
        for (int i = 0; i < len - 1; i++) {
            if (arr[i] >= arr[i + 1]) {
                return false;
            }
        }
        return true;
    }
};

int fun() {
    Solution solution;
    TreeNode *treeNode = stringToTreeNode("[0,null,-1]");
    bool ret = solution.isValidBST(treeNode);
    printf("%s", ret ? "true" : "false");
    return 0;
}

