/* -*- coding: utf-8 -*-
  !@time: 2019-10-20 19:01
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 1.cpp
 */
#include <iostream>
#include <vector>
using namespace std;
int fun() {
    int n, m;
    while (cin >> n >> m) {
        vector<int> eachGroupPeople(n);
        int people_num;
        for (int i = 0; i < n; i++) {
            cin>>people_num;
            eachGroupPeople.push_back(people_num);
        }
        vector<vector<int>> groups;
        int x, y;
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
        }
    }

}