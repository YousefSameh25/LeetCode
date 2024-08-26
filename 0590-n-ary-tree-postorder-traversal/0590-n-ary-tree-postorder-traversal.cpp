/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

void Traverse (Node* node, vector < int > & ans)
{
    if (node == nullptr)
        return;
    
    for (auto it : node -> children)
        Traverse(it, ans);
    
    ans.push_back(node -> val);
}

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector < int > ans;
        Traverse(root, ans);
        return ans;
    }
};