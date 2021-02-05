#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        if(s.size() == 0) {
            return 0;
        }

        int start = 0, end = 0, cost = abs(s[0] - t[0]);
        int longest_len = 0, now_len = 0;
        while(end < s.size()) {

            if(cost <= maxCost) {
                now_len += 1;
                end += 1;
                cost += abs(s[end] - t[end]);
            } else {
                cost -= abs(s[start] - t[start]);
                start += 1;
                now_len -= 1;
            }

            if (now_len > longest_len) {
                longest_len = now_len;
            }
        }

        return longest_len;
    }
};

int main() {
    Solution s;
    string str1 = "abcd";
    string str2 = "bcdf";
    int maxCost = 4;
    cout << s.equalSubstring(str1, str2, maxCost);
}
