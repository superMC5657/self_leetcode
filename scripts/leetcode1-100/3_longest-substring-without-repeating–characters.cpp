

#include <assert.h>
#include <iostream>
#include <map>
#include "stdio.h"


using namespace std;

class Solution {
public:
    // 暴力法 O(n^3)
//    int lengthOfLongestSubstring(string s) {
//        int a = 0;
//        string str;
//        string sub_s;
//        bool flag;
//        for (int i = 0; i < s.size(); i++) {
//            int b = 0;
//            str = "";
//            flag = false;
//            sub_s = s.substr(i);
//            for (char d : sub_s) {
//                for (char m:str) {
//                    if (d == m) {
//                        flag = true;
//                        break;
//                    }
//                }
//                if (flag) {
//                    break;
//                }
//                str += d;
//                b++;
//            }
//            if (b > a) {
//                a = b;
//            }
//        }
//        return a;
//    }
    // 滑动窗口法 O(n^2)
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        map<char, int> Map_tmp;
        map<char, int>::iterator iter; //:: 表示一个域
        int i = 0, ans = 0;

        for (int j = 0; j < n; j++) {
            auto map_end = Map_tmp.end();
            iter = Map_tmp.find(s[j]); //没找到 返回最后一位。 找到了则first 为s[j]
            if (iter != map_end) {
                i = max(i, iter->second); //iter->second 就是int类型 iter就是中间的hashmap的一个元素组
            }
            ans = max(ans, j - i + 1); // length 为 j（某元素位置） - i（上一个同元素位置） +1
            Map_tmp[(s[j])] = j + 1; //
        }
        return ans;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() - 1; i++) {// 为了省略双引号 所以掐头去尾
        char currentChar = input[i];
        if (input[i] == '\\') { //   string中char的'\'实际上'\\'表示 ;
            char nextChar = input[i + 1];
            switch (nextChar) {
                case '\"':
                    result.push_back('\"'); //这是\"
                    break;
                case '/' :
                    result.push_back('/');
                    break;
                case '\\':
                    result.push_back('\\'); //两个 \\ 表示为\;
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
            i++; //检测到\时一次使用两个char
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        int ret = Solution().lengthOfLongestSubstring(s);
        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}