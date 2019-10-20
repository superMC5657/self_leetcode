/* -*- coding: utf-8 -*-
  !@time: 2019-09-22 02:34
  !@author: superMC @email: 18758266469@163.com
  !@fileName: substring.cpp
 */

#include "environment.h"
#include "function.hpp"


class Solution {
    typedef unordered_map<string, int> umap;
public:
    static vector<int> findSubstring(string s, vector<string> &words) {
        vector<int> res;
        if (s.empty() || words.empty()) {
            return res;
        }
        int word_len = words[0].size();
        umap mp1, mp2;
        for (auto & word : words) {
            if (mp1.find(word) == mp1.end()) {
                mp1.insert(std::pair<string, int>(word, 1));
                mp2.insert(std::pair<string, int>(word, 0));
            } else {
                mp1[word] += 1;
            }
        }

        for (int j = 0; j < word_len; ++j) {
            string tmp_s = s.substr(j, s.size() - j);
            if (tmp_s.size() < words.size() * word_len) {
                return res;
            }
            for (int i = 0; tmp_s.size() / word_len - words.size() >= i; ++i) {
                if (i == 0) {
                    for (int k = 0; k < words.size(); ++k) {
                        if (mp2.find(tmp_s.substr(k * word_len, word_len)) != mp2.end())
                            mp2[tmp_s.substr(k * word_len, word_len)] += 1;
                    }
                } else {
                    if (mp2.find(tmp_s.substr((i - 1) * word_len, word_len)) != mp2.end())
                        mp2[tmp_s.substr((i - 1) * word_len, word_len)] -= 1;
                    if (mp2.find(tmp_s.substr((i - 1 + words.size()) * word_len, word_len)) != mp2.end())
                        mp2[tmp_s.substr((i - 1 + words.size()) * word_len, word_len)] += 1;
                }
                if (isSmae(mp1, mp2)) {
                    res.push_back(i * word_len + j);
                }
            }
            for (auto &item : mp2) {
                item.second = 0;
            }
        }
        return res;
    }

    static bool isSmae(umap &mp1, umap &mp2) {
        for (const auto &iterator : mp1) {
            if (iterator.second != mp2[iterator.first]) {
                return false;
            }
        }
        return true;
    }
};

int fun() {
    string s = "a";
    string words_str = "[a,a]";
    vector<string> words = stringToStringVector(words_str);
    vector<int> ret = Solution::findSubstring(s, words);
    string out = integerVectorToString(ret);
    cout << out << endl;
    return 0;
}