//
// Created by 张研 on 2019-07-28.
//
#include <vector>
#include "iostream"

using namespace std;

class Solution {
public:
    string convert(const string &s, int numRows) {
        string result;
        int n = 2 * numRows - 2;
        if (n == 0) {
            return s;
        }
        vector<vector<char >> res(numRows);
        for (int i = 0; i < s.length(); i++) {
            int pos = i % n;
            if (pos < numRows) {
                res[pos].push_back(s[i]);
            } else {
                pos = n - pos;
                res[pos].push_back(s[i]);
            }
        }
        for (vector<char> sub_res:res) {
            result += vectorToString(sub_res);
        }
        return result;
    }

    static string vectorToString(vector<char> s, int length = -1) {
        if (length == -1) {
            length = s.size();
        }

        if (length == 0) {
            return "";
        }

        string result;
        for (int index = 0; index < length; index++) {
            char c = s[index];
            result += c;
        }
        return result;
    }

    string convert_better(string s, int numRows) {
        if (numRows == 1) return s;

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string ret;
        for (string row : rows) ret += row;
        return ret;

    }

};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() - 1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i + 1];
            switch (nextChar) {
                case '\"':
                    result.push_back('\"');
                    break;
                case '/' :
                    result.push_back('/');
                    break;
                case '\\':
                    result.push_back('\\');
                    break;
                case 'b' :
                    result.push_back('\b');
                    break;
                case 'f' :
                    result.push_back('\f');
                    break;
                case 'r' :
                    result.push_back('\r');
                    break;
                case 'n' :
                    result.push_back('\n');
                    break;
                case 't' :
                    result.push_back('\t');
                    break;
                default:
                    break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

int stringToInteger(const string &input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        int numRows = stringToInteger(line);

        string ret = Solution().convert(s, numRows);
        string out = (ret);
        cout << out << endl;
    }
    return 0;
}