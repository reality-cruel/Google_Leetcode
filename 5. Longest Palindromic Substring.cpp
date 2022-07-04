#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include<vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        int l = 0, r = 0;//store the substring idx
        bool* p = new bool[len * len];
        memset(p, 0, len * len);

        if (!s.size()) return 0;
        //initialize the two dimension array p[i][i]=1, p[i][i+1] with condition
        for (int i = 0; i < len; i++) {
            *(p + i * len + i) = 1;
        }

        for (int i = 0; i < len - 1; i++) {
            if (s[i] == s[i + 1]) {
                l = i;
                r = i + 1;
                *(p + i * len + i + 1) = 1;
            }
        }

        for (int gap = 2; gap < len; gap++) {
            for (int i = 0; i < len - gap; i++) {
                int j = gap + i;
                if (s[i] == s[j] && *(p + (i + 1) * len + (j - 1)) == 1) {
                    *(p + i * len + j) = 1;
                    l = i;
                    r = j;
                }
            }
        }
        return s.substr(l, r - l + 1);
    }
};

int main() {

    return 0;
}

