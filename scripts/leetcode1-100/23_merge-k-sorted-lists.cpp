/* -*- coding: utf-8 -*-
  !@time: 2019/9/13 22:54
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 23_merge.cpp
 */

#include <environment.h>


class Solution {
public:

    ListNode *mergeKLists(vector<ListNode *> &list) {
        int list_length = list.size();
        if (0 == list_length) {
            return nullptr;
        }
        if (1 == list_length) {
            return list[0];
        }
        ListNode *res = new ListNode(-1);
        ListNode *tmp = res;

        vector<pair<int, int>> vtMap;
        for (int i = 0; i < list.size(); i++) {
            if (list[i] == nullptr) {
                list_length--;
            } else {
                vtMap.push_back(std::make_pair(i, list[i]->val));
            }
        }
        sort(vtMap.begin(), vtMap.end(),
             [](const pair<int, int> &x, const pair<int, int> &y) -> int {
                 return x.second < y.second;
             });
        if (vtMap.empty()) {
            return nullptr;
        }
        int flag = 0;
        while (1) {
            int index = vtMap[0].first;
            tmp->next = list[index];
            tmp = tmp->next;
            if (list[index]->next != nullptr) {
                list[index] = list[index]->next;
                vtMap[0].second = list[index]->val;
            } else {
                flag++;
                vtMap[0].second = INT32_MAX;
            }
            for (int i = 1; i < list_length; i++) {
                if (vtMap[i - 1].second > vtMap[i].second) {
                    int second_tmp = vtMap[i - 1].second;
                    vtMap[i - 1].first = vtMap[i].first;
                    vtMap[i - 1].second = vtMap[i].second;
                    vtMap[i].first = index;
                    vtMap[i].second = second_tmp;
                } else {
                    break;
                }
            }
            if (flag == list_length) {
                break;
            }
        }
        return res->next;
    }

    struct cmp {
        bool operator()(ListNode *l1, ListNode *l2) {
            return l1->val > l2->val;
        }
    };

    ListNode *mergeKLists_template(vector<ListNode *> &lists) {
        vector<ListNode *> mergeKlist;
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        std::priority_queue<ListNode *, vector<ListNode *>, cmp> MinHeap;//从大到小就是小顶堆
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] != nullptr) {
                MinHeap.push(lists[i]);
            }
        }
        while (!MinHeap.empty()) {
            ListNode *tmp = MinHeap.top();
            MinHeap.pop();
            cur->next = tmp;
            cur = cur->next;
            if (tmp->next)
                MinHeap.push(tmp->next);

        }
        return dummy->next;

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
    string line = "[[1,4,5],[1,3,4],[2,6]]";

    for (int i = 0; i < 10000; i++) {
        vector<ListNode *> list = stringToVectorListNode(line);
        ListNode *ret = Solution().mergeKLists(list);
        string out = listNodeToString(ret);
        //cout << out << endl;
    }
    return 0;
}