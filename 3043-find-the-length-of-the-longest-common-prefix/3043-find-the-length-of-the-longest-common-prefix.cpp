class Solution {
public:
    class TrieNode {
    public:
        TrieNode* children[26];
        TrieNode()
        {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    } root;
    
    void CreatPrefixTree(vector<int>& arr1)
    {
        for (int i = 0 ; i < arr1.size(); i++)
            Insert(arr1[i]);
    }

    void Insert(int x)
    {
        TrieNode* node = &root;
        string num = to_string(x);
        for (char c : num) {
            int index = c - '0';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node -> children[index];
        }
    }
    int getSharedprefix(int x)
    {
        TrieNode* node = &root;
        string num = to_string(x);
        int ans = 0;
        for (char c : num) {
            int index = c - '0';
            if (!node->children[index]) {
                break;
            } else {
                ans++;
            }
            node = node -> children[index];
        }
        return ans;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        CreatPrefixTree(arr1);
        int mx = -1;
        for (auto it : arr2)
            mx = max(mx, getSharedprefix(it));
        return mx;
    }
};