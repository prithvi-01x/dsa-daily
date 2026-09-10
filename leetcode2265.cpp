#include <utility>

using namespace std;

class Solution {
    int ans = 0;

    pair<int, int> dfs(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }
        auto [leftSum, leftCount] = dfs(root->left);
        auto [rightSum, rightCount] = dfs(root->right);

        int sum = root->val + leftSum + rightSum;
        int count = 1 + leftCount + rightCount;

        if (root->val == sum / count) {
            ans++;
        }

        return {sum, count};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};
