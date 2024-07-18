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
    map < TreeNode*, TreeNode* > parent;
    vector < TreeNode* > nodes;

    void dfs (TreeNode* node)
    {
        if (node -> left == nullptr and node -> right == nullptr)
            nodes.push_back(node);
        if (node -> left != nullptr)
        {
            parent[node -> left] = node;
            dfs(node -> left);
        }
        if (node -> right != nullptr)
        {
            parent[node -> right] = node;
            dfs(node -> right);
        }
    }

    void GetPath (TreeNode* node, vector < TreeNode* > &Path)
    {
        while(node != nullptr)
        {
            Path.push_back(node);
            node = parent[node];
        }
        reverse (Path.begin(), Path.end());
    }


    int countPairs(TreeNode* root, int distance) {
        dfs(root);
        int ans = 0;

        map < TreeNode* , vector < TreeNode* >> path;
        for (int i = 0 ; i < nodes.size(); i++)
            GetPath(nodes[i], path[nodes[i]]);
        


        for (int i = 0 ; i < nodes.size(); i++)
        {
            for (int j = i + 1; j < nodes.size(); j++)
            {
                int ii = 0;
                while(ii < min(path[nodes[i]].size(), path[nodes[j]].size()) and path[nodes[i]][ii] == path[nodes[j]][ii])
                    ii++;
                
                int rem = (path[nodes[i]].size() - ii) + (path[nodes[j]].size() - ii);
                ans += rem <= distance;
            }
        }
        return ans;
    }
};