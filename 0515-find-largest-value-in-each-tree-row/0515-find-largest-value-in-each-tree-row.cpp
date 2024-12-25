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
    vector < int > BFS(TreeNode* root)
    {
        queue < TreeNode* > q;
        q.push(root);
        vector < int > mxLst; 
        while (q.size())
        {
            int n = q.size();
            int mx = INT_MIN;
            while(n--)
            {
                auto node = q.front();
                q.pop();
                mx = max(mx , node -> val);
                if (node -> left != nullptr)
                {
                    q.push(node -> left);
                }
                if (node -> right != nullptr)
                {
                    q.push(node -> right);
                }
            }
            mxLst.push_back(mx);
        }
        return mxLst;
    }
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr)
            return {};
        return BFS(root);
    }
};