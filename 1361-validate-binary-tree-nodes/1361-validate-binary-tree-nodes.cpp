class Solution {
public:
    vector < int > g[10000+ 10];
    bool vis[10000 + 10];
    void dfs (int node)
    {   
        vis[node]=  1;
        for (auto &ch : g[node])
        {
            if (not vis[ch])
                dfs(ch);
        }
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) 
    {
        // Tree is one component and has no cy.
        // Binary tree is indegree <= 2
        vector < int > indeg (n , 0);
        for (int i = 0 ; i < n ; i++)
        {
            if (leftChild[i] >= 0)
            {
              indeg[leftChild[i]]++;
              g[i].push_back(leftChild[i]);
              if (indeg[leftChild[i]] >= 2)
                   return false;
            }

            if (rightChild[i] >= 0)
            {
                indeg[rightChild[i]]++;
                g[i].push_back(rightChild[i]);
                if (indeg[rightChild[i]] >= 2)
                   return false; 
            }
        }
        for (int i = 0 ; i < n ; i++)
        {
            if (indeg[i] == 0)
            {
                dfs (i);
                break;
            }
        }
        for (int i = 0 ; i < n ; i++)
        {
          if (not vis[i])
              return false;
        }
        return true;
    }
};