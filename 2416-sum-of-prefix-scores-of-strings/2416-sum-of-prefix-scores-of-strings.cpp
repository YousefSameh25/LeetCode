class Node
{
    public:
    int cnt;
    Node* children[26];
    Node()
    {
        cnt = 0;
        for (int i = 0 ; i < 26 ; i++)
            children[i] = nullptr;
    }
};
class Solution {
public:
    int Insert(Node* root,string &word)
    {
        int ans = 0;
        for (auto &it : word)
        {
            int idx = it - 'a';
            if (root -> children[idx] == nullptr)
                root -> children[idx] = new Node();

            root = root -> children[idx];
            root -> cnt++;
            ans += root -> cnt;
        }
        return ans;
    }
    void Delete(Node *root,string &word)
    {
        for (auto &it : word)
        {
            int idx = it - 'a';
            root = root -> children[idx];
            root -> cnt--;
        }
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        Node* root = new Node();

        for (auto &word : words)
            Insert(root, word);
        
        vector < int > ans;
        for (auto &word : words)
        {
            Delete(root, word);
            ans.push_back(Insert(root, word));
        }
        return ans;
    }
};