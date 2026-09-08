#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> ones;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                ones.push_back(i);
            }
        }
        if (ones.size() < k) {
            return "";
        }
        string ans = "";
        for (int i = 0; i + k - 1 < ones.size(); ++i) {
            string cur = s.substr(ones[i], ones[i + k - 1] - ones[i] + 1);
            if (ans.empty() || cur.length() < ans.length() || (cur.length() == ans.length() && cur < ans)) {
                ans = cur;
            }
        }
        return ans;
    }
};
