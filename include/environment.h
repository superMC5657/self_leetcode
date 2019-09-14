/* -*- coding: utf-8 -*-
  !@time: 2019-09-11 15:05
  !@author: superMC @email: 18758266469@163.com
  !@fileName: environment.h
 */
#ifndef SELF_LEETCODE_ENVIROMENT_H
#define SELF_LEETCODE_ENVIROMENT_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <stack>
#include <map>
#include <queue>

using std::stack;
using std::unordered_map;
using std::map;
using std::pair;
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::to_string;
using std::stringstream;
using std::sort;
using std::max;
using std::min;

struct ListNode {
    int val;
    ListNode *next;

    //make me can use ListNode(5)
    ListNode(int x) : val(x), next(nullptr) {
    }
};

#endif //SELF_LEETCODE_ENVIROMENT_H
