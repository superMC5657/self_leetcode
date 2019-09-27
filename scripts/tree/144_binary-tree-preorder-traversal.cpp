/* -*- coding: utf-8 -*-
  !@time: 2019-09-26 10:12
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 144_binary.cpp
 */

#include <environment.h>
#include <function.hpp>

class Solution {
    vector<int> res;
public:
    vector<int> preorderTraversal(TreeNode *root) {
        if (root) {
            res.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return res;
    }
};

int fun() {
    string str = "[1,null,2,3]";
    TreeNode *root = stringToTreeNode(str);
    vector<int> ret = Solution().preorderTraversal(root);
    string out = integerVectorToString(ret);
    cout << out << endl;
    return 0;
}