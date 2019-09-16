/* -*- coding: utf-8 -*-
  !@time: 2019-09-16 11:54
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 1117_building.cpp
 */

// vs2015 update3 win64
#include <functional>
#include <thread>
#include <chrono>
#include <mutex>

// 题目的代码模板
class H2O {
    std::mutex m;
    std::condition_variable cv;
    int state = 1;
public:
    H2O() {
    }

    void hydrogen(std::function<void()> releaseHydrogen) {
        std::unique_lock<std::mutex> lock(m);
        cv.wait(lock, [=]() { return state != 3; });
        releaseHydrogen();
        ++state;
        cv.notify_all();
    }

    void oxygen(std::function<void()> releaseOxygen) {
        std::unique_lock<std::mutex> lock(m);
        cv.wait(lock, [=]() { return state == 3; });
        releaseOxygen();
        state = 1;
        cv.notify_all();
    }
};

// 题目的代码模板 -- end

void HThread(H2O *c) {
    c->hydrogen([]() {
        printf("H");
    });
}

void OThread(H2O *c) {
    c->oxygen([]() {
        printf("O");
    });
}


void fun() {

    std::string test = "HOHOHHOOHOHHHHHOHHHOHO";
    H2O *h2O = new H2O;// new  可以执行H2O()  初始化H2O;
    printf("input str: %s\n", test.c_str());
    for (int i = 0; i < test.size(); ++i) {
        if (test[i] == 'O') {
            std::thread *th = new std::thread(OThread, h2O);
        } else if (test[i] == 'H') {
            std::thread *th = new std::thread(HThread, h2O);
        }
    }

    // std::this_thread::sleep_for(std::chrono::seconds(1));

}

