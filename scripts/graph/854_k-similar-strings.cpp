/* -*- coding: utf-8 -*-
  !@time: 2019-09-24 14:25
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 854_k.cpp
 */

#include <environment.h>
#include <function.hpp>

class solution {
    template<class Iterator>

    int DFS(Iterator a_st, Iterator a_ed, Iterator b_st, Iterator b_ed, int used_depth, int max_depth) {
        for (; a_st != a_ed && *a_st == *b_st; a_st++, b_st++);

        if (a_st == a_ed)
            return used_depth;
        else if (used_depth == max_depth)
            return max_depth;
        else {
            for (auto i = std::next(a_st), j = std::next(b_st); i != a_ed; i++, j++) {
                if (*i == *b_st && *i != *j && *j == *a_st) {
                    std::iter_swap(i, a_st);

                    max_depth = DFS(std::next(a_st), a_ed, std::next(b_st), b_ed, used_depth + 1, max_depth);

                    std::iter_swap(i, a_st);

                    return max_depth;
                }
            }

            for (auto i = std::next(a_st), j = std::next(b_st); i != a_ed; i++, j++) {
                if (*i == *b_st && *i != *j) {
                    std::iter_swap(i, a_st);

                    max_depth = std::min(max_depth,
                                         DFS(std::next(a_st), a_ed, std::next(b_st), b_ed, used_depth + 1, max_depth));

                    std::iter_swap(i, a_st);
                }
            }

            return max_depth;
        }
    }


public:
    int kSimilarity(string A, string B) {
        return DFS(A.begin(), A.end(), B.begin(), B.end(), 0, A.size());
    }
};


int fun() {
    string line;
    while (getline(cin, line)) {
        string A = stringToString(line);
        getline(cin, line);
        string B = stringToString(line);

        int ret = solution().kSimilarity(A, B);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}