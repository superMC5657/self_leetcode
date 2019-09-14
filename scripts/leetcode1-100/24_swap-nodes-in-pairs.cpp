/* -*- coding: utf-8 -*-
  !@time: 2019/9/14 21:53
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 24_swap.cpp
 */
#include "environment.h"

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *res = new ListNode(-1);
        ListNode *res_tmp = res;
        if (head == nullptr) {
            return nullptr;
        }
        while (1) {
            if (head->next == nullptr) {
                res_tmp->next = head;
                break;
            }
            ListNode *tmp = head;
            ListNode *tmp_2 = head->next;
            head = head->next->next;
            tmp->next = nullptr;
            tmp_2->next = nullptr;
            res_tmp->next = tmp_2;
            res_tmp = res_tmp->next;
            res_tmp->next = tmp;
            res_tmp = res_tmp->next;
            if (head == nullptr) {
                break;
            }
        }
        return res->next;
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

ListNode *stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

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

int fun() {
    string line;
    while (getline(cin, line)) {
        ListNode *head = stringToListNode(line);

        ListNode *ret = Solution().swapPairs(head);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}