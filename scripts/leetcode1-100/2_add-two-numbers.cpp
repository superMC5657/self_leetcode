//
// Created by Administrator on 2019/6/18.
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iostream>


using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {
    }
};

string listNodeToString(ListNode *node);

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) { //返回一个指针
        ListNode *result = new ListNode(-1);
        int len_l1 = 1;
        int len_l2 = 1;
        ListNode *p = l1; // 定义一个指针 赋予他指针l1的值
        ListNode *q = l2;
        while (p->next != nullptr) {
            len_l1++;
            p = p->next;
        }
        while (q->next != nullptr) {
            len_l2++;
            q = q->next;
        }
        if (len_l1 > len_l2)//l1较长，在l2首位置补零
        {
            for (int i = 1; i <= (len_l1 - len_l2); i++) {
                q->next = new ListNode(0);
                q = q->next;
            }
        } else//l2较长，在l1首位置补零
        {
            for (int i = 1; i <= (len_l2 - len_l1); i++) {
                p->next = new ListNode(0);
                p = p->next;
            }
        }
        // l1 l2:[1, 6, 7, 2, 1, 4, 6, 0, 0, 0, 0][6, 4, 7, 5, 1, 2, 3, 5, 4, 7, 8]
        // p q: [0] [8] p,q 在于
        //cout << listNodeToString(l1) << listNodeToString(l2) << endl;
        p = l1;
        q = l2;
        int sub_sum;
        bool carry = false;
        ListNode *res = result; //移动result的指针.
        while (p != nullptr && q != nullptr) {
            sub_sum = carry + p->val + q->val; //bool
            res->next = new ListNode(sub_sum % 10);
            carry = sub_sum >= 10;
            res = res->next;
            p = p->next;
            q = q->next;
        }
        if (carry) {
            res->next = new ListNode(1);
            res = res->next;
        }
        return result->next; //头插法不改变result 因为首地址变化了.

    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) { //& 作为引用类型即可修改传递 类似c# ref
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
        // 输入list反序

        ListNode *l1 = stringToListNode(line);
        cout << listNodeToString(l1);
        getline(cin, line);
        ListNode *l2 = stringToListNode(line);

        ListNode *ret = Solution().addTwoNumbers(l1, l2);
        cout << listNodeToString(l1);
        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}