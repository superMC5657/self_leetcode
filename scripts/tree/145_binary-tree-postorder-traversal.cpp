/* -*- coding: utf-8 -*-
  !@time: 2019-09-26 10:17
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 145_binary.cpp
 */
#include <environment.h>
#include <function.hpp>

class Solution {
    vector<int> res;
public:
    vector<int> postorderTraversal(TreeNode *root) {
        if (root) {

            postorderTraversal(root->left);
            postorderTraversal(root->right);
            res.push_back(root->val);
        }
        return res;
    }
};

int fun() {
    string str = "[1,null,2,3]";
    TreeNode *root = stringToTreeNode(str);
    vector<int> ret = Solution().postorderTraversal(root);
    string out = integerVectorToString(ret);
    cout << out << endl;
    return 0;
}