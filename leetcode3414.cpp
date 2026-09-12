#include <vector>
#include <array>
#include <algorithm>

using namespace std;

class Solution {
    struct Interval {
        int l, r, weight, idx;
    };

    struct Element {
        long long weight = -1;
        int count = 0;
        array<int, 4> id{};
    };

    static bool isBetter(const Element& a, const Element& b) {
        if (b.weight == -1) return true;
        if (a.weight != b.weight) return a.weight > b.weight;
        return lexicographical_compare(a.id.begin(), a.id.begin() + a.count,
                                       b.id.begin(), b.id.begin() + b.count);
    }

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }

        sort(arr.begin(), arr.end(), [](const Interval& a, const Interval& b) {
            if (a.r != b.r) return a.r < b.r;
            return a.l < b.l;
        });

        vector<array<Element, 5>> dp(n + 1);
        for (int i = 0; i <= n; ++i) {
            dp[i][0].weight = 0;
            dp[i][0].count = 0;
        }

        for (int i = 0; i < n; ++i) {
            int l = 0, r = i;
            int target = arr[i].l;
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (arr[mid].r >= target) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            int k = l;

            for (int j = 1; j <= 4; ++j) {
                Element best = dp[i][j];

                if (dp[k][j - 1].weight != -1) {
                    Element cand;
                    cand.weight = dp[k][j - 1].weight + arr[i].weight;
                    cand.count = j;
                    int p = 0;
                    while (p < j - 1 && dp[k][j - 1].id[p] < arr[i].idx) {
                        cand.id[p] = dp[k][j - 1].id[p];
                        p++;
                    }
                    cand.id[p] = arr[i].idx;
                    while (p < j - 1) {
                        cand.id[p + 1] = dp[k][j - 1].id[p];
                        p++;
                    }

                    if (isBetter(cand, best)) {
                        best = cand;
                    }
                }

                dp[i + 1][j] = best;
            }
        }

        Element bestOverall;
        bestOverall.weight = -1;
        for (int j = 1; j <= 4; ++j) {
            if (dp[n][j].weight == -1) continue;
            if (isBetter(dp[n][j], bestOverall)) {
                bestOverall = dp[n][j];
            }
        }

        return vector<int>(bestOverall.id.begin(), bestOverall.id.begin() + bestOverall.count);
    }
};
