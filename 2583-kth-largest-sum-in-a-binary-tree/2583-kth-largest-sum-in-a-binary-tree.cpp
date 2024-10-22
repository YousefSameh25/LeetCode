/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector < long long > sum;
    void dfs(TreeNode* node, int lvl)
    {
        if (node == nullptr)
            return;

        sum[lvl] += node -> val;

        dfs(node -> left, lvl + 1);
        dfs(node -> right, lvl + 1);
    }

    long long kthLargestLevelSum(TreeNode* root, int k) {
        sum.resize(100000 + 1, 0);
        dfs(root, 1);
        sort(sum.begin(), sum.end(), greater< long long>());
        k--;
        return sum[k] ? sum[k] : -1;
    }
};