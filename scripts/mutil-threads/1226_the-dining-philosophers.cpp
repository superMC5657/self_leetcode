/* -*- coding: utf-8 -*-
  !@time: 2019/10/29 22:38
  !@author: superMC @email: 18758266469@163.com
  !@fileName: 1226_the.cpp
 */
#include <environment.h>
#include <function.hpp>

class DiningPhilosophers {
public:
    DiningPhilosophers() {

    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {

    }
};

int fun() {
    string line;
    while (getline(cin, line)) {
        int target = stringToInteger(line);

        int ret = Solution().foobar(target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}