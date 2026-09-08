#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int distinctSubseqII(string s) {
        constexpr int kMod = 1'000'000'007;
        int ends_with[26] = {0};
        int total = 0;
        for (char c : s) {
            int idx = c - 'a';
            int old = ends_with[idx];
            ends_with[idx] = (total + 1) % kMod;
            total = (total + ends_with[idx] - old) % kMod;
            if (total < 0) {
                total += kMod;
            }
        }
        return total;
    }
};
