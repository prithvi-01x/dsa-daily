class Solution {
public:
    long long countCommas(long long n) {
        long long total = 0;
        for (long long base = 1000; base <= n; ) {
            total += n - base + 1;
            if (base > n / 1000) {
                break;
            }
            base *= 1000;
        }
        return total;
    }
};
