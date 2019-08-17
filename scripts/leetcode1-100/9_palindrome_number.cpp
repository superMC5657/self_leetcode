//
// Created by 张研 on 2019-08-17.
//
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int length = 0;
        int x_copy = x;
        int y = 0;
        while (1) {
            x_copy /= 10;
            length += 1;
            if (x_copy < 1) {
                break;
            }
        }
        x_copy = x;
        for (int i = 0; i < length; i++) {

            y += (x_copy % 10) * pow(10, length - i - 1);
            x_copy /= 10;
        }
        if (x == y) {
            return true;
        } else {
            return false;
        }
    }

    bool isPalindrome_fast(int x) {
        if (x < 0 || 0 != x && x % 10 == 0) {
            return false;
        }

        int rev = 0;

        while (x > rev) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }

        return rev == x || rev / 10 == x;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int fun() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);

        bool ret = Solution().isPalindrome_fast(x);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}