/* -*- coding: utf-8 -*-
  !@time: 2019-10-01 11:16
  !@author: superMC @email: 18758266469@163.com
  !@fileName: smallest.cpp
 */
#include <environment.h>
#include <function.hpp>

class solution {
public:
    vector<int> indices;                                                 //Stores indices of same group.
    vector<bool> visited;
    vector<vector<int>> adjList;
    string indiceString;                                                 //Stores  string formed by indices in the same group.
    void dfs(string &s, int n)                                             //DFS to get all indices in same group.
    {
        visited[n] = true;
        indices.push_back(n);
        indiceString += s[n];
        for (int &i:adjList[n])
            if (!visited[i])
                dfs(s, i);
    }

    string smallestStringWithSwaps_dfs(string s, vector<vector<int>> &pairs) {
        adjList.resize(s.length());
        visited.resize(s.length(), false);
        for (vector<int> &v:pairs)                               //Create adjacency list using the indice pairs
            adjList[v[0]].push_back(v[1]), adjList[v[1]].push_back(v[0]);
        for (int i = 0; i < s.length(); i++)
            if (!visited[i]) {
                indiceString = "";                              //Clear string formed by one group of indices before finding next group.
                indices.clear();                             //Clear indices vector before finding another group.
                dfs(s, i);
                sort(indiceString.begin(),
                     indiceString.end());                    //Sort the characters in the same group.
                sort(indices.begin(),
                     indices.end());                                  //Sort the indices in the same group.
                for (int i = 0; i <
                                indices.size(); i++)          //Replace all the indices in the same group with the sorted characters.
                    s[indices[i]] = indiceString[i];
            }
        return s;
    }

    int find_father(int A[], int x) {
        if (A[x] == x) {
            return x;
        }
        //return find_father(A,A[x]);
        return A[x] = find_father(A, A[x]);//改成这样主要是要更新该节点的根节点
    }

    void A_union(int A[], int x, int y) {
        //A[find_father(A,x)]=y;
        A[find_father(A, x)] = find_father(A, y);//改成这样主要是要实现压缩路径
    }

    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
        //分集和

        //初始化，每一个集合中一个元素
        int A[s.length()];
        for (int i = 0; i < s.length(); i++) {
            A[i] = i;
        }
        //这里每个集合实际上就是一个连通图，为了存储和查找时间复杂度为O(n)
        //所以我们以最小连通图的方式存储，也就是对每个集合采用树的形式存储
        for (int i = 0; i < pairs.size(); i++) {
            A_union(A, pairs[i][0], pairs[i][1]);
        }
        //以上的操作基本上形成了以索引为节点的森林，森林中的每棵树为一个集合
        //接下来就要将索引映射到每个字符了
        /*for(int i=0;i<s.length();i++)
        {
            cout<<A[i]<<endl;
        }*/
        vector<char> v_char[s.length()];
        for (int i = 0; i < s.length(); i++) {
            v_char[find_father(A, i)].push_back(s[i]);
        }
        //接下来把每个集合中的字符排序
        for (int i = 0; i < s.length(); i++) {
            if (v_char[i].size() == 0) {
                continue;
            }
            sort(v_char[i].begin(), v_char[i].end(), std::greater<char>());//这里采用升序，原因是方便后续pop
        }
        //将划分好集合的字符整合


        for (int i = 0; i < s.length(); i++) {
            s[i] = *(v_char[find_father(A, i)].end() - 1);
            /*cout<<*(v_char[A[i]].end()-1)<<endl;*/
            v_char[find_father(A, i)].pop_back();
        }

        return s;
    }

};

int fun() {
    string str = "dcab";
    string strPairs = "[[0,3],[1,2]]";
    vector<vector<int>> pairs = stringToVectorVectorInteger(strPairs);
    string ret = solution().smallestStringWithSwaps(str, pairs);
    cout << ret << endl;
    return 0;
}