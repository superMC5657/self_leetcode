/* -*- coding: utf-8 -*-
  !@time: 2020-01-25 08:19
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 99_recover.cpp
 */
#include <environment.h>
#include <function.hpp>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//https://www.youtube.com/watch?v=QZMropFflv4&t=3s
//time:o(N)
//space:o(h),worser case(inorder space is o(h)))
//1//3,1,4,null,null,2
//2//2,1,4,null,null,3
//二叉搜索树的中序遍历是从小到大排序的，
//1inorde:  1，5, 3，4，2, 6
// 	          pre cur
//            first = pre
//1inorde:  1，5, 3，4， 2, 6
//							    pre cur
//                  second = cur
//swap first->val and second->val
//2inorder: 1,2,3,4,5,6
class Solution_n {
private:
    TreeNode *first = nullptr;
    TreeNode *second = nullptr;
    TreeNode *pre = new TreeNode(INT_MIN);

    void helper(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        helper(root->left);
        if (first == nullptr && pre->val > root->val) {
            first = pre;
        }
        if (first != nullptr && pre->val > root->val) {
            second = root;
        }
        pre = root;
        helper(root->right);
    }

public:
    void recoverTree(TreeNode *root) {
        helper(root);
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//https://www.youtube.com/watch?v=QZMropFflv4&t=3s
//time:o(N)
//space:o(h),worser case(inorder space is o(h)))
//1//3,1,4,null,null,2
//2//2,1,4,null,null,3
//二叉搜索树的中序遍历是从小到大排序的，
//1inorde:  1，5, 3，4，2, 6
// 	          pre cur
//            first = pre
//1inorde:  1，5, 3，4， 2, 6
//							    pre cur
//                  second = cur
//swap first->val and second->val
//2inorder: 1,2,3,4,5,6
class Solution_1 {
private:
    TreeNode *first = nullptr;
    TreeNode *second = nullptr;
    TreeNode *pre = new TreeNode(INT_MIN);

    void helper(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        helper(root->left);
        if (first == nullptr && pre->val > root->val) {
            first = pre;
        }
        if (first != nullptr && pre->val > root->val) {
            second = root;
        }
        pre = root;
        helper(root->right);
    }

public:
    void recoverTree(TreeNode *root) {
        helper(root);
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }

};

int fun() {
    string inputStr = "[1,3,null,null,2]";
    TreeNode *input = stringToTreeNode(inputStr);
    Solution_1().recoverTree(input);
    string output = treeNodeToString(input);
    printf("%s", output.c_str());
    return 0;
}

