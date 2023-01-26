/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    int vis[110];
    vector <int> g[110];
    void dfs (Node* node)
    {
        vis[node -> val] = 1;
        for (auto child : node -> neighbors)
        {
            g[node -> val].push_back(child -> val);
            if (vis[child -> val])
                continue;
            dfs(child);
        }
    }
    Node* cloneGraph(Node* node) 
    {  
        if (node == NULL)
            return NULL;
        dfs(node);
        map <int , Node*> mp;
        for (int i = 1 ; i <= 100 ; i++)
        {
            if (vis[i] == 0)
                continue;
            
            if (not mp.count(i))
                mp[i] = new Node(i);
            
            for (int child : g[i])
            {
                if (not mp.count(child))
                   mp[child] = new Node(child);
                mp[i] -> neighbors.push_back(mp[child]);
            }
        }
        return mp[1];
    }
    
};