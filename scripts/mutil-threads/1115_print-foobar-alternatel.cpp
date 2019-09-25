/* -*- coding: utf-8 -*-
  !@time: 2019-09-16 11:17
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 1115_print.cpp
 */
#include <environment.h>
#include <thread>

class FooBar {
private:
    int n;
    pthread_mutex_t one = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_t two = PTHREAD_MUTEX_INITIALIZER;

public:
    FooBar(int n) {
        this->n = n;
        pthread_mutex_init(&one, nullptr);
        pthread_mutex_init(&two, nullptr);
        pthread_mutex_lock(&two);
    }

    void foo(function<void()> printFoo) {

        for (int i = 0; i < n; i++) {

            // printFoo() outputs "foo". Do not change or remove this line.
            pthread_mutex_lock(&one);
            printFoo();
            pthread_mutex_unlock(&two);
        }
    }

    void bar(function<void()> printBar) {

        for (int i = 0; i < n; i++) {

            // printBar() outputs "bar". Do not change or remove this line.
            pthread_mutex_lock(&two);
            printBar();
            pthread_mutex_unlock(&one);
        }
        printf("\n");
    }
};


void fooThread(FooBar *fooBar) {
    fooBar->foo([]() {
        printf("Foo");
    });
}

void barThread(FooBar *fooBar) {
    fooBar->bar([]() {
        printf("Bar");
    });
}

int stringToInteger(string input) {
    return stoi(input);
}

int fun() {
    string line;
    while (getline(cin, line)) {
        int count = stringToInteger(line);
        FooBar *fooBar = new FooBar(count);
        std::thread *foo = new std::thread(fooThread, fooBar);
        std::thread *bar = new std::thread(barThread, fooBar);
        foo->join();
        bar->join();
    }
    return 0;
}