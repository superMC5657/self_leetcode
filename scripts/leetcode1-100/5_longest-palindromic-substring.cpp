/* -*- coding: utf-8 -*-
  !@time: 2019/6/21 0:21
  !@author: superMC @email: 18758266469@163.com
  !@fileName: longest_palindromic_substring.cpp
 */

#include <iostream>
#include <assert.h>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    int m = 0;

    // 暴力法 O(n^3)
    string longestPalindrome_0(string s) {
        string result;
        string tmp; //缓存
        string tmp_reverse;
        int s_length = s.length();
        for (int i = s_length; i > 0; i--) {
            tmp = s.substr(s_length - i);
            for (int j = i; j > 0; j--) {
                tmp_reverse = tmp;
                reverse(tmp_reverse.begin(), tmp_reverse.end());// 翻转str T=n
                //tmp_reverse.reserve(); error
                if (tmp == tmp_reverse) {
                    result = result.length() > tmp.length() ? result : tmp; //题目要求后者
                    break;
                }
                tmp.pop_back();
            }
        }
        return result;
    }

    //最长公共子串
    string longestPalindrome(string s) {
        if (s.length() == 1) return s;//大小为1的字符串必为回文串
        string rev = s;//rev存放s反转结果
        string res;//存放结果
        std::reverse(rev.begin(), rev.end());
        string temp;//存放待验证子串
        string q;//q用来验证temp是否是回文子串
        if (rev == s) return s;
        int len = 0;//存放回文子串的长度
        for (int i = 0; i < s.length(); i++)//查找s与rev的最长公共子串
        {
            for (int j = i; j < s.length(); j++) {
                temp += s[j];
                if (len >= temp.length()) { //没res大 肯定不用更新
                    continue;
                } else if (rev.find(temp) != -1)//在rev中找到temp 如果现在找不到之后更找不到！！！
                {
                    q = temp;
                    std::reverse(q.begin(), q.end());
                    if (q == temp) {
                        len = temp.length();
                        res = temp;
                    }
                } else {
                    break;
                }
            }
            temp = "";
        }
        return res;
    }
    //中心扩展法

    string longestPalindrome_center(string s) {
        int len = s.size();
        if (len == 0 || len == 1)
            return s;
        int start = 0;//记录回文子串起始位置
        int end = 0;//记录回文子串终止位置
        int mlen = 0;//记录最大回文子串的长度
        for (int i = 0; i < len; i++) {
            int len1 = expendaroundcenter(s, i, i);//一个元素为中心
            int len2 = expendaroundcenter(s, i, i + 1);//两个元素为中心
            mlen = max(max(len1, len2), mlen);
            if (mlen > end - start + 1) { //确保mlen比之前长才会更新
                start = i - (mlen - 1) / 2;//根据长度和中心推起始点
                end = i + mlen / 2;
            }
        }
        return s.substr(start, mlen);
        //该函数的意思是获取从start开始长度为mlen长度的字符串
    }

    //dp
    string longestPalindrome_manacher(string s) {
        int len = s.length();
        if (len < 1) {
            return "";
        }

        // 预处理
        string s1;
        for (int i = 0; i < len; i++) {
            s1 += "#";
            s1 += s[i];
        }
        s1 += "#";

        len = s1.length();
        int MaxRight = 0;                // 当前访问到的所有回文子串，所能触及的最右一个字符的位置
        int pos = 0;                    // MaxRight对应的回文串的对称轴所在的位置
        int MaxRL = 0;                    // 最大回文串的回文半径
        int MaxPos = 0;                    // MaxRL对应的回文串的对称轴所在的位置
        int *RL = new int[len];            // RL[i]表示以第i个字符为对称轴的回文串的回文半径
        memset(RL, 0, len * sizeof(int));
        for (int i = 0; i < len; i++) {
            m++;
            if (i < MaxRight) {// 1) 当i在MaxRight的左边
                RL[i] = min(RL[2 * pos - i], MaxRight - i);
            } else {// 2) 当i在MaxRight的右边
                RL[i] = 1;
            }


            // 尝试扩展RL[i]，注意处理边界
            while (i - RL[i] >= 0  // 可以把RL[i]理解为左半径,即回文串的起始位不能小于0
                   && i + RL[i] < len // 同上,即回文串的结束位不能大于总长
                   && s1[i - RL[i]] == s1[i + RL[i]]// 回文串特性，左右扩展，判断字符串是否相同
                    ) {
                RL[i] += 1;
            }

            // 更新MaxRight, pos
            if (RL[i] + i - 1 > MaxRight) {
                MaxRight = RL[i] + i - 1;
                pos = i;
            }

            // 更新MaxRL, MaxPos
            if (MaxRL <= RL[i]) {
                MaxRL = RL[i];
                MaxPos = i;
            }
        }
        return s.substr((MaxPos - MaxRL + 1) / 2, MaxRL - 1);
    }

private:
    int expendaroundcenter(string s, int left, int right)
    //计算以left和right为中心的回文串长度
    {
        int L = left;
        int R = right;
        while (L >= 0 && R < s.length() && s[R] == s[L]) { //不越界且左边等于右边
            L--;
            R++;
        }
        return R - L - 1;
    }
    // Manacher

};


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

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        Solution solution;
        string ret = solution.longestPalindrome_manacher(s);
        cout << "计算次数:" << solution.m << endl;
        cout << ret << endl;
    }
    return 0;
}