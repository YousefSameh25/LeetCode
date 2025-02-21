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
class FindElements {
    private:
    set < int > st;
    void solve(TreeNode* root, int value)
    {
        if (root == nullptr)
            return;
        root -> val = value;
        st.insert(value);
        solve(root -> left, 2 * value + 1);
        solve(root -> right, 2 * value + 2);
    }
public:
    FindElements(TreeNode* root) {
        solve(root, 0);
    }
    
    bool find(int target) {
        return st.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */