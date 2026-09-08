#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        int L = 0;
        vector<int> temp = count;
        while (L < n && temp[target[L] - 'a'] > 0) {
            temp[target[L] - 'a']--;
            L++;
        }

        vector<int> cur_cnt = count;
        for (int j = 0; j < min(n - 1, L); ++j) {
            cur_cnt[target[j] - 'a']--;
        }

        for (int i = min(n - 1, L); i >= 0; --i) {
            for (int c = target[i] - 'a' + 1; c < 26; ++c) {
                if (cur_cnt[c] > 0) {
                    cur_cnt[c]--;
                    string res = target.substr(0, i);
                    res += (char)('a' + c);
                    for (int ch = 0; ch < 26; ++ch) {
                        res.append(cur_cnt[ch], (char)('a' + ch));
                    }
                    return res;
                }
            }
            if (i > 0) {
                cur_cnt[target[i - 1] - 'a']++;
            }
        }
        return "";
    }
};
