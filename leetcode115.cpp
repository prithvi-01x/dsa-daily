#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        if (m < n) {
            return 0;
        }
        vector<vector<int>> pos(128);
        for (int j = n - 1; j >= 0; --j) {
            pos[(unsigned char)t[j]].push_back(j + 1);
        }
        vector<unsigned long long> dp(n + 1, 0);
        dp[0] = 1;
        for (char c : s) {
            for (int j : pos[(unsigned char)c]) {
                dp[j] += dp[j - 1];
            }
        }
        return dp[n];
    }
};
