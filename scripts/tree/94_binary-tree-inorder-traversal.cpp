/* -*- coding: utf-8 -*-
  !@time: 2019-09-26 08:45
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 94_binary.cpp
 */
#include <environment.h>
#include <function.hpp>

class Solution {
    vector<int> res;
public:
    vector<int> inorderTraversal(TreeNode *root) {
        if (root) {
            inorderTraversal(root->left);
            res.push_back(root->val);
            inorderTraversal(root->right);
        }
        return res;
    }
    vector<int> inorderTraversalIteration(TreeNode *root) {
        vector<int> v;
        stack<TreeNode> s;
        TreeNode* t=root;
        while(t||!s.empty()){
            while(t){
                s.push(*t);
                t=t->left;
            }
            v.push_back(s.top().val);
            t=s.top().right;
            s.pop();
        }
        return v;
    }
};

int fun() {
    string str = "[1,null,2,3]";
    TreeNode *root = stringToTreeNode(str);
    vector<int> ret = Solution().inorderTraversal(root);
    string out = integerVectorToString(ret);
    cout << out << endl;
    return 0;
}