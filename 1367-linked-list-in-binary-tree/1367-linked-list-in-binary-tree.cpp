/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool dfs2 (ListNode* ptr, TreeNode* node)
    {
        if (ptr == nullptr)
            return 1;
        if (node == nullptr)
            return 0;
        
        int ans = 0;
        if (node -> val == ptr -> val)
        {
            ans |= dfs2(ptr -> next, node -> left);
            ans |= dfs2(ptr -> next, node -> right);
        } 
        return ans;
    }
    vector < TreeNode* > roots;
    void dfs1 (TreeNode* node, ListNode* head)
    {
        if (node == nullptr)
            return;
        if (node -> val == head -> val)
            roots.push_back(node);

        dfs1(node -> left, head);
        dfs1(node -> right, head);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        
        dfs1(root, head);
        for(auto it: roots)
        {
            if (dfs2(head, it))
                return 1;
        }
        return 0;
    }
};