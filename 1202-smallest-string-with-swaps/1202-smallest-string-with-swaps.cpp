class Solution {
public:
    
    vector < int > G[100000];
    vector < int > vis;
    
    void dfs (int node, vector <int>& com)
    {
        vis[node] = 1;
        com.push_back(node);
        
        for (auto& child : G[node])
        {
            if (vis[child])
                continue;
            dfs(child, com);
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        vis.resize(s.size(), 0);
        
        for (auto it : pairs)
        {
            G[it[0]].push_back(it[1]);
            G[it[1]].push_back(it[0]);
        }
        
        for (int i = 0 ; i < s.size(); i++)
        {
            if (vis[i])
                continue;
            
            vector < int > comIndexes;
            dfs (i, comIndexes);
            
            string sub;
            
            for (auto it : comIndexes)
                sub.push_back(s[it]);
            
            sort(sub.begin(), sub.end());
            sort(comIndexes.begin(), comIndexes.end());
            
            for (int j = 0 ; j < comIndexes.size() ; j++)
                s[comIndexes[j]] = sub[j]; 
        }
        
        return s;
    }
};