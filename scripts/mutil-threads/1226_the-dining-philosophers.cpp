/* -*- coding: utf-8 -*-
  !@time: 2019/10/29 22:38
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 1226_the.cpp
 */
#include <environment.h>
#include <function.hpp>
#include <thread>

class DiningPhilosophers_template {
    std::mutex m;
    std::condition_variable cv;
    bool occur[5];

public:
    DiningPhilosophers_template() {
        for (int i = 0; i < 5; i++) {
            occur[i] = false;
        }
    }

    void wantsToEat(int philosopher,
                    function<void(int)> pickLeftFork,
                    function<void(int)> pickRightFork,
                    function<void(int)> eat,
                    function<void(int)> putLeftFork,
                    function<void(int)> putRightFork) {
        int left = philosopher;
        int right = (philosopher + 1) % 5;

        vector<function<void(int)>> pick = {pickLeftFork, pickRightFork};
        vector<function<void(int)>> put = {putLeftFork, putRightFork};
        int val = 0;

        if (left > right) {
            std::swap(left, right);
            val = 1;
        }

        {
            std::unique_lock<std::mutex> lk(m);

            cv.wait(lk, [&]() { return !occur[left] && !occur[right]; });
            occur[left] = true;
            occur[right] = true;

            pick[val](philosopher);
            pick[val ^ 1](philosopher);
        }

        eat(philosopher);

        put[val](philosopher);
        put[val ^ 1](philosopher);

        occur[left] = false;
        occur[right] = false;

        cv.notify_all();
    }
};

class semaphore {
public:
    explicit semaphore(int count = 0) : count_(count) {
    }

    void set(int count) {
        count_ = count;
    }

    void signal() {
        std::unique_lock<std::mutex> lock(mutex_);
        ++count_;
        cv_.notify_one();
    }

    void wait() {
        std::unique_lock<std::mutex> lock(mutex_);
        while (count_ <= 0) {
            cv_.wait(lock);
        }
        --count_;
    }

private:
    std::mutex mutex_;
    std::condition_variable cv_;
    int count_;
};

class DiningPhilosophers {
public:
    DiningPhilosophers() {
        guid.set(4);
    }

    void wantsToEat(int philosopher,
                    function<void(int)> pickLeftFork,
                    function<void(int)> pickRightFork,
                    function<void(int)> eat,
                    function<void(int)> putLeftFork,
                    function<void(int)> putRightFork) {
        int l = philosopher;
        int r = (philosopher + 1) % 5;
        guid.wait();

        lock[l].lock();
        lock[r].lock();
        pickLeftFork(philosopher);
        pickRightFork(philosopher);
        eat(philosopher);
        putRightFork(philosopher);
        putLeftFork(philosopher);
        lock[r].unlock();
        lock[l].unlock();

        guid.signal();
    }

private:
    std::mutex lock[5];
    semaphore guid;
};

void pickLeftFunc(int philosopher) {
    printf("哲学家%d拿起左叉  ", philosopher);
}

void pickRightFunc(int philosopher) {
    printf("哲学家%d拿起右叉  ", philosopher);
}

void EatFunc(int philosopher) {
    printf("哲学家%d吃面  ", philosopher);
}

void putLeftFunc(int philosopher) {
    printf("哲学家%d放下左叉  ", philosopher);
}

void putRightFunc(int philosopher) {
    printf("哲学家%d放下右叉  ", philosopher);
}


int fun_self() {
    typedef DiningPhilosophers DPT;
    DPT dPhilosophers;


    //& :: 形式(function) 再传递new的新的对象;
    std::thread t1(&DPT::wantsToEat, &dPhilosophers, 1, pickLeftFunc, pickRightFunc, EatFunc,
                   putLeftFunc,
                   putRightFunc);
    std::thread t2(&DPT::wantsToEat, &dPhilosophers, 2, pickLeftFunc, pickRightFunc, EatFunc,
                   putLeftFunc,
                   putRightFunc);
    std::thread t3(&DPT::wantsToEat, &dPhilosophers, 3, pickLeftFunc, pickRightFunc, EatFunc,
                   putLeftFunc,
                   putRightFunc);
    std::thread t4(&DPT::wantsToEat, &dPhilosophers, 4, pickLeftFunc, pickRightFunc, EatFunc,
                   putLeftFunc,
                   putRightFunc);
    std::thread t5(&DPT::wantsToEat, &dPhilosophers, 5, pickLeftFunc, pickRightFunc, EatFunc,
                   putLeftFunc,
                   putRightFunc);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    return 0;
}

int fun() {
    auto pickLeftFork = [](int philosopher) { std::cout << "[" << philosopher << ", 1, 1], "; };
    auto pickRightFork = [](int philosopher) { std::cout << "[" << philosopher << ", 2, 1], "; };
    auto eat = [](int philosopher) { std::cout << "[" << philosopher << ", 0, 3], "; };
    auto putLeftFork = [](int philosopher) { std::cout << "[" << philosopher << ", 1, 2], "; };
    auto putRightFork = [](int philosopher) { std::cout << "[" << philosopher << ", 2, 2], "; };
    auto execute = [&](int n) {
        DiningPhilosophers diningPhilosophers;
        std::thread t1(&DiningPhilosophers::wantsToEat, &diningPhilosophers, 1, pickLeftFork,
                       pickRightFork, eat, putLeftFork, putRightFork);
        std::thread t2(&DiningPhilosophers::wantsToEat, &diningPhilosophers, 2, pickLeftFork,
                       pickRightFork, eat, putLeftFork, putRightFork);
        std::thread t3(&DiningPhilosophers::wantsToEat, &diningPhilosophers, 3, pickLeftFork,
                       pickRightFork, eat, putLeftFork, putRightFork);
        std::thread t4(&DiningPhilosophers::wantsToEat, &diningPhilosophers, 4, pickLeftFork,
                       pickRightFork, eat, putLeftFork, putRightFork);
        std::thread t5(&DiningPhilosophers::wantsToEat, &diningPhilosophers, 5, pickLeftFork,
                       pickRightFork, eat, putLeftFork, putRightFork);
        t1.join();
        t2.join();
        t3.join();
        t4.join();
        t5.join();
    };

    execute(1);
    std::cout << std::endl;
    return 0;
}
