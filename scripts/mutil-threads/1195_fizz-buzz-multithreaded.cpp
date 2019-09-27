/* -*- coding: utf-8 -*-
  !@time: 2019-09-26 13:35
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 1195_fizz.cpp
 */

#include <environment.h>
#include <function.hpp>
#include <thread>

class FizzBuzz {
private:
    int n;
    std::mutex m;
    std::condition_variable cv;
    int state = 1;
public:
    FizzBuzz(int n) {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (1) {
            std::unique_lock<std::mutex> lock(m);
            if (state > this->n) { return; }
            cv.wait(lock, [=]() {
                return (state % 3 == 0 && state % 5 != 0);
            });
            printFizz();
            ++state;
            cv.notify_all();
        }

    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (1) {
            std::unique_lock<std::mutex> lock(m);
            if (state > this->n) { return; }
            cv.wait(lock, [=]() {
                return (state % 3 != 0 && state % 5 == 0);
            });
            printBuzz();
            ++state;
            cv.notify_all();
        }

    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        while (1) {
            std::unique_lock<std::mutex> lock(m);
            if (state > this->n) { return; }
            cv.wait(lock, [=]() {
                return (state % 3 == 0 && state % 5 == 0);
            });
            printFizzBuzz();
            ++state;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (1) {
            std::unique_lock<std::mutex> lock(m);
            if (state > this->n) { return; }
            cv.wait(lock, [=]() {
                return (state % 3 != 0 && state % 5 != 0);
            });
            printNumber(state);
            ++state;
            cv.notify_all();

        }
    }
};

class FizzBuzz_template {
private:
    int n;
    int count;
    std::mutex m;
    std::condition_variable cv;

public:
    FizzBuzz_template(int n) {
        this->n = n;
        this->count = 1;
    }

    void fizz(function<void()> printFizz) {
        while (true) {
            std::unique_lock <std::mutex> lock(m);
            while (count <= n && (count % 3 != 0 || count % 5 == 0))
                cv.wait(lock);
            if (count > n) return;
            printFizz();
            ++count;
            cv.notify_all();
        }
    }

    void buzz(function<void()> printBuzz) {
        while (true) {
            std::unique_lock <std::mutex> lock(m);
            while (count <= n && (count % 5 != 0 || count % 3 == 0))
                cv.wait(lock);
            if (count > n) return;
            printBuzz();
            ++count;
            cv.notify_all();
        }
    }

    void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            std::unique_lock <std::mutex> lock(m);
            while (count <= n && (count % 5 != 0 || count % 3 != 0))
                cv.wait(lock);
            if (count > n) return;
            printFizzBuzz();
            ++count;
            cv.notify_all();
        }
    }

    void number(function<void(int)> printNumber) {
        while (true) {
            std::unique_lock <std::mutex> lock(m);
            while (count <= n && (count % 5 == 0 || count % 3 == 0))
                cv.wait(lock);
            if (count > n) return;
            printNumber(count++);
            cv.notify_all();
        }
    }
};

void fizzFunc(FizzBuzz_template *fizzBuzz) {
    fizzBuzz->fizz([]() {
        printf("fizz, ");
    });
}

void buzzFunc(FizzBuzz_template *fizzBuzz) {
    fizzBuzz->buzz([]() {
        printf("buzz, ");
    });
}

void fizzBuzzFunc(FizzBuzz_template *fizzBuzz) {
    fizzBuzz->fizzbuzz([]() {
        printf("fizzBuzz, ");
    });
}

void numberFunc(FizzBuzz_template *fizzBuzz) {
    fizzBuzz->number([](int i) {
        cout << i << endl;
    });
}

int fun() {
    int n = 15;
    FizzBuzz_template *fizzBuzz = new FizzBuzz_template(n);
    std::thread *fizzT = new std::thread(fizzFunc, fizzBuzz);
    std::thread *buzzT = new std::thread(buzzFunc, fizzBuzz);
    std::thread *fizzBuzzT = new std::thread(fizzBuzzFunc, fizzBuzz);
    std::thread *numberT = new std::thread(numberFunc, fizzBuzz);

    fizzT->join();
    buzzT->join();
    fizzBuzzT->join();
    numberT->join();
    return 0;
}
