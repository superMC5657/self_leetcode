/* -*- coding: utf-8 -*-
  !@time: 2020/10/9 7:18 下午
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 1.cpp
 */
#include <iostream>


class A {
    A() = default;

    virtual ~A() = default;
    char data;

};

int main() {
    int m = sizeof(A);
    std::cout << m << std::endl;
    return 0;
}