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
    TreeNode* reverseOddLevels(TreeNode* root) 
    {
        deque < int > vls;
        vector <TreeNode*> nodes;
        //Get Level
        map <TreeNode* , int> lvl;
        lvl[root] = 0;
        queue < TreeNode* > q;
        q.push(root);
        while(q.size())
        {
            int n = q.size();
            vector <int> tmp;
            while(n--)
            {
                TreeNode* f = q.front();
                q.pop();
                if (lvl[f] & 1)
                    tmp.push_back( f-> val) , nodes.push_back(f);
                if (f -> left != NULL)
                {
                    q.push(f -> left);
                    q.push(f -> right);
                    lvl[f -> left] = lvl[f] + 1;
                    lvl[f -> right] = lvl[f] + 1;
                }
            }
            while (tmp.size()) {
                vls.push_back(tmp.back());
                tmp.pop_back();
            }
        }
        
        for (auto node : nodes)
        {
            node -> val = vls.front();
            vls.pop_front();
        }
        return root;
    }
};