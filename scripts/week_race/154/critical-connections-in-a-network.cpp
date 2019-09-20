/* -*- coding: utf-8 -*-
  !@time: 2019-09-19 19:59
  !@author: superMC @email: 18758266469@163.com
  !@fileName: critical.cpp
 */
#include "environment.h"

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections) {
        typedef unordered_map<int, vector<vector<int >>> umap;
        umap record;
        vector<vector<int>> res;
        for (const vector<int> &item : connections) {
            for (int item_int : item) {
                record[item_int].push_back(item);
            }
        }
        for (auto iter : record) {
            if (iter.second.size() == 1) {
                res.push_back(iter.second[0]);
            }
        }
        return res;
    }
};


class Solution_template {
    const static int MAXN = 100010;
    const static int MAXM = 100010;
    //树的数组形式储存
    int Head[MAXN], Next[MAXM * 2], To[MAXM * 2];
    int n, tot;

    //dfn 储存每个定点的唯一编号
    //low 储存当前定点能到达的最小编号
    int dfn[MAXN], low[MAXN];

    int numIndex, numCutedge; //答案
    struct Edge {
        int u, v;
    } cutedge[MAXM];

    void Tarjan(int u, int pre = -1) {
        if (dfn[u] != -1) return;
        dfn[u] = low[u] = ++numIndex;//分配唯一编号

        for (int i = Head[u]; i != -1; i = Next[i]) {
            int v = To[i];
            if (v == pre)continue;
            Tarjan(v, u);

            low[u] = min(low[u], low[v]);//如有有更小编号，更新
            if (low[v] > dfn[u]) {
                cutedge[numCutedge++] = {u, v}; //找到一个答案
            }
        }
    }

    void solve() {
        memset(dfn, -1, sizeof(dfn));
        memset(low, -1, sizeof(low));
        numCutedge = 0;
        numIndex = 0;
        Tarjan(0); //由于是连通图，随便找个定点开始搜就行了
    }

    void Outit(vector<vector<int>> &ans) {
        for (int i = 0; i < numCutedge; i++) {
            ans.push_back({cutedge[i].u, cutedge[i].v});
        }
    }

    void add_eage(int x, int y) {
        tot++;
        Next[tot] = Head[x];
        Head[x] = tot;
        To[tot] = y;
    }

    void ReadInfo(int n, vector<vector<int>> &conn) {
        memset(Head, -1, sizeof(Head));
        tot = 0;
        this->n = n;
        for (auto &v: conn) {
            int x = v[0];
            int y = v[1];
            add_eage(x, y);
            add_eage(y, x);
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &conn) {
        ReadInfo(n, conn);
        solve();

        vector<vector<int>> ans;
        Outit(ans);
        return ans;
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

int stringToInteger(string input) {
    return stoi(input);
}

int fun() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);
        getline(cin, line);
        vector<vector<int>> list = stringToVectorVectorInteger(line);
        vector<vector<int>> res = Solution_template().criticalConnections(num, list);
        string out = "";
        for (const vector<int> &item : res) {
            out += integerVectorToString(item);
            out += "\n";
        }
        cout << out << endl;
    }
    return 0;


}