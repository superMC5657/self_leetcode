/* -*- coding: utf-8 -*-
  !@time: 2019-09-20 15:27
  !@author: superMC @email: 18758266469@163.com
  !@fileName: function.hpp
 */
#ifndef SELF_LEETCODE_FUNCTION_HPP
#define SELF_LEETCODE_FUNCTION_HPP

#include <assert.h>

#include <utility>

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

int stringToInteger(string input) {
    return stoi(input);
}

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() - 1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i + 1];
            switch (nextChar) {
                case '\"':
                    result.push_back('\"');
                    break;
                case '/' :
                    result.push_back('/');
                    break;
                case '\\':
                    result.push_back('\\');
                    break;
                case 'b' :
                    result.push_back('\b');
                    break;
                case 'f' :
                    result.push_back('\f');
                    break;
                case 'r' :
                    result.push_back('\r');
                    break;
                case 'n' :
                    result.push_back('\n');
                    break;
                case 't' :
                    result.push_back('\t');
                    break;
                default:
                    break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

string listNodeToString(ListNode *node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

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

vector<vector<int>> stringToVectorVectorInteger(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    vector<vector<int>> res;
    char delim = ']';
    int i = 0;
    while (getline(ss, item, delim)) {
        if (i == 0) {
            vector<int> l = stringToIntegerVector(item + "]");
            res.push_back(l);
        } else {
            res.push_back(stringToIntegerVector(item.substr(1, item.size()) + ']'));
        }
        i++;
    }
    return res;
}

vector<char> stringToCharVector(string input) {
    vector<char> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    for (char c : input) {
        if (c != ',')
            if (c != '"')
                output.push_back(c);
    }
    return output;
}

vector<vector<char >> stringToVectorVectorChar(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    vector<vector<char >> res;
    char delim = ']';
    int i = 0;
    while (getline(ss, item, delim)) {
        if (i == 0) {
            vector<char> l = stringToCharVector(item + "]");
            res.push_back(l);
        } else {
            res.push_back(stringToCharVector(item.substr(1, item.size()) + ']'));
        }
        i++;
    }
    return res;
}

string charVectorToString(vector<char> input, int length = -1) {
    if (length == -1) {
        length = input.size();
    }
    if (length == 0) {
        return "[]";
    }

    string res;
    for (int index = 0; index < length; index++) {
        res += input[index];
        res += ", ";
    }
    return "[" + res.substr(0, res.length() - 2) + "]";
}

string charVectorVectorToString(vector<vector<char >> &input, int length = -1) {
    if (length == -1) {
        length = input.size();
    }
    if (length == 0) {
        return "[]";
    }
    string res;
    for (int i = 0; i < length; i++) {
        res += charVectorToString(input[i]);
        res += "\n";
    }
    return res;
}

ListNode *stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(std::move(input));

    // Now convert that list into linked list
    ListNode *dummyRoot = new ListNode(0);
    ListNode *ptr = dummyRoot;
    for (int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

vector<ListNode *> stringToVectorListNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    vector<ListNode *> res;
    char delim = ']';
    int i = 0;
    while (getline(ss, item, delim)) {
        if (i == 0) {
            ListNode *l = stringToListNode(item + "]");
            res.push_back(l);
        } else {
            res.push_back(stringToListNode(item.substr(1, item.size()) + ']'));
        }

        i++;
    }
    return res;

}

TreeNode *stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (input.empty()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode *root = new TreeNode(stoi(item));
    std::queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode *node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

vector<string> stringToStringVector(string input) {
    vector<string> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(item);
    }
    return output;
}

string integerVectorVectorToString(vector<vector<int>> &arr, int length = -1) {
    if (length == -1) {
        length = arr.size();
    }
    if (length == 0) {
        return "[]";
    }
    string res;
    for (int i = 0; i < length; i++) {
        res += integerVectorToString(arr[i]);
        res += "\n";
    }
    return res;
}

void sortInts(int a, int b, int c, int arr[3]) {
    int d;
    if (a > b) {
        d = a;
        a = b;
        b = d;
    }
    if (b > c) {
        d = b;
        b = c;
        c = d;
    }
    if (a > c) {
        d = a;
        a = c;
        c = d;
    }
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
}

#endif //SELF_LEETCODE_FUNCTION_HPP
