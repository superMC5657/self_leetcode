/* -*- coding: utf-8 -*-
  !@time: 2019-09-15 01:07
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 25_reverse.cpp
 */

#include <environment.h>

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *res = new ListNode(-1);
        ListNode *res_tmp = res;
        if (head == nullptr) {
            return nullptr;
        }
        bool flag = false;
        while (1) {
            ListNode *head_tmp = head;
            vector<ListNode *> tmp_list;
            for (int i = 0; i < k; i++) {
                if (head_tmp == nullptr) {
                    flag = true;
                    break;
                }
                ListNode *tmp = head_tmp;
                head_tmp = head_tmp->next;
                tmp->next = nullptr;
                tmp_list.push_back(tmp);
            }
            head = head_tmp;
            if (flag) {
                for (int i = 0; i < tmp_list.size(); i++) {
                    res_tmp->next = tmp_list[i];
                    res_tmp = res_tmp->next;
                }
                break;
            }
            for (int i = 0; i < k; i++) {
                res_tmp->next = tmp_list[k - 1 - i];
                res_tmp = res_tmp->next;
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

int stringToInteger(string input) {
    return stoi(input);
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
        getline(cin, line);
        int k = stringToInteger(line);

        ListNode *ret = Solution().reverseKGroup(head, k);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}