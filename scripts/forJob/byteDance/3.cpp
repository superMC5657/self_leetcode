/* -*- coding: utf-8 -*-
  !@time: 2019-10-20 19:37
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 3.cpp
 */

#include <iostream>
#include <stack>

using namespace std;

int get_yueNum(int mo, int de) {
    int temp;
    while (de != 0) {
        temp = mo % de;
        mo = de;
        de = temp;
    }
    return mo;
}

void transformer(int &de, int &mo, int add) {
    mo = add * de + mo;
    int yueNum = get_yueNum(mo, de);
    mo = mo / yueNum;
    de = de / yueNum;
}

int fun() {
    int n;
    while (cin >> n) {
        if (n <= 1) {
            int inputTmp;
            cin >> inputTmp;
            cout << 1 << " " << inputTmp;
            continue;
        }
        stack<int> stack_ct;
        int input_tmp;
        for (int i = 0; i < n; i++) {
            cin >> input_tmp;
            stack_ct.push(input_tmp);
        }
        int flag = 0;
        int de;
        int mo;
        while (!stack_ct.empty()) {
            if (flag == 0) {
                de = stack_ct.top();
                mo = 1;
                stack_ct.pop();
                int add = stack_ct.top();
                stack_ct.pop();
                transformer(de, mo, add);
            } else {
                int tmp = de;
                de = mo;
                mo = tmp;
                int add = stack_ct.top();
                stack_ct.pop();
                transformer(de, mo, add);
            }
            flag++;
        }
        cout << mo << " " << de << endl;
    }
    return 0;
}

