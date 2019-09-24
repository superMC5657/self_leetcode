/* -*- coding: utf-8 -*-
  !@time: 2019-09-24 17:00
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 1116_print.cpp
 */
#include <environment.h>
#include <function.hpp>
#include <thread>

class ZeroEvenOdd {
private:
    int n;
    pthread_mutex_t zeroLock;
    pthread_mutex_t evenLock;
    pthread_mutex_t oddLock;


public:
    explicit ZeroEvenOdd(int n) {
        this->n = n;
        pthread_mutex_init(&zeroLock, nullptr);
        pthread_mutex_init(&oddLock, nullptr);
        pthread_mutex_init(&evenLock, nullptr);
        pthread_mutex_lock(&oddLock);
        pthread_mutex_lock(&evenLock);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(const function<void(int)> &printNumber) {

        for (int i = 1; i <= this->n; i++) {
            pthread_mutex_lock(&zeroLock);
            printNumber(0);
            if (i % 2 != 0) {
                pthread_mutex_unlock(&oddLock);
            } else {
                pthread_mutex_unlock(&evenLock);
            }
        }
    }

    void odd(const function<void(int)> &printNumber) {
        for (int i = 1; i <= this->n; i += 2) {
            pthread_mutex_lock(&oddLock);
            printNumber(i);
            pthread_mutex_unlock(&zeroLock);
        }

    }

    void even(const function<void(int)> &printNumber) {
        for (int i = 2; i <= this->n; i += 2) {
            pthread_mutex_lock(&evenLock);
            printNumber(i);
            pthread_mutex_unlock(&zeroLock);
        }
    }
};

void zeroThread(ZeroEvenOdd *zeroEvenOdd) {
    zeroEvenOdd->zero([](int x) {
        printf("%d", x);
    });
}

void oddThread(ZeroEvenOdd *zeroEvenOdd) {
    zeroEvenOdd->odd([](int x) {
        printf("%d", x);
    });
}

void evenThread(ZeroEvenOdd *zeroEvenOdd) {
    zeroEvenOdd->even([](int x) {
        printf("%d", x);
    });
}

int fun() {
    string line;
    while (getline(cin, line)) {
        int limit = stringToInteger(line);

        auto *zeroEvenOdd = new ZeroEvenOdd(limit);
        auto *zero_t = new std::thread(zeroThread, zeroEvenOdd);
        auto *odd_t = new std::thread(oddThread, zeroEvenOdd);
        auto *even_t = new std::thread(evenThread, zeroEvenOdd);

        zero_t->join();
        odd_t->join();
        even_t->join();
        printf("\n");
    }
    return 0;
}