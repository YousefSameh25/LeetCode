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
private:
    int GetNumber(int& i, string& traversal)
    {
        string num;
        while(i < traversal.size() and traversal[i] >= '0' and traversal[i] <= '9')
            num.push_back(traversal[i++]);
        return stoi(num);
    }
    int GetLevel(int& i, string& traversal)
    {
        int lvl = 0;
        while(i < traversal.size() and traversal[i] == '-')
            lvl++, i++;
        return lvl;
    }
public:
    TreeNode* recoverFromPreorder(string traversal) {
        map < int , TreeNode* > mp;
        int i = 0;
        int nodeVal = GetNumber(i, traversal);
        TreeNode* node = new TreeNode(nodeVal);
        TreeNode* root = node;
        mp[0] = node;
        
        while(i < traversal.size())
        {
            int nodeLvl = GetLevel(i, traversal);
            nodeVal = GetNumber(i, traversal);

            node = new TreeNode(nodeVal);

            if (mp[nodeLvl - 1] -> left == nullptr)
            {
                mp[nodeLvl - 1]-> left = node;
            }
            else if (mp[nodeLvl - 1] -> right == nullptr)
            {
                mp[nodeLvl - 1]-> right = node;
            }
            mp[nodeLvl] = node;
        }
        return root;
    }
};