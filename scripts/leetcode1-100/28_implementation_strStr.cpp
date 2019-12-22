/* -*- coding: utf-8 -*-
  !@time: 2019/12/21 8:16
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 28_implementation_strStr.cpp
 */
#include <environment.h>


class Solution_internal {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;
        if (haystack.size() < needle.size())
            return -1;
        int lenhay = haystack.size();
        int lennee = needle.size();
        for (int i = 0; i <= lenhay - lennee; ++i) {
            if (haystack.substr(i, lennee) == needle)
                return i;
        }
        return -1;
    }
};

class Solution_kmp {
public:
    vector<int> getnext(string str) {
        int len = str.size();
        vector<int> next;
        next.push_back(-1);//next数组初值为-1
        int j = 0, k = -1;
        while (j < len - 1) {
            if (k == -1 || str[j] == str[k])//str[j]后缀 str[k]前缀
            {
                j++;
                k++;
                next.push_back(k);
            } else {
                k = next[k];
            }
        }
        return next;
    }

    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;

        int i = 0;//源串
        int j = 0;//子串
        int len1 = haystack.size();
        int len2 = needle.size();
        vector<int> next;
        next = getnext(needle);
        while ((i < len1) && (j < len2)) {
            if ((j == -1) || (haystack[i] == needle[j])) {
                i++;
                j++;
            } else {
                j = next[j];//获取下一次匹配的位置
            }
        }
        if (j == len2)
            return i - j;

        return -1;
    }
};


int fun() {
    string haystack, needle;
    haystack = "HelloWorld";
    needle = "World";
    printf("%d", Solution_kmp().strStr(haystack, needle));

}