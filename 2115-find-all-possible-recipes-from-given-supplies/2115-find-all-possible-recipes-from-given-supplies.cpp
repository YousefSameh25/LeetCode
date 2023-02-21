class Solution {
public:
    set<string>res;
    map<string , int> vis;
    // 1 in progress
    // 2 finished
    bool dfs (string node , map<string ,vector<string>> & mp ,set<string>& s)
    {
        if(mp[node].empty())
            return s.count(node);
        if(s.count(node))
            return 1;
        bool ok = 1;
        vis[node] = 1;
        for(string ch : mp[node])
        {
            if(vis[ch] == 1)
                 return 0;
              ok &= dfs(ch , mp , s);
        }

        if(ok)
            s.insert(node) , res.insert(node);
         vis[node] = 2;
        return ok;
    }

    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {

        set<string> s(supplies.begin() , supplies.end());
        map<string ,vector<string>> mp;
        for(int i = 0 ; i < recipes.size() ; i++)
        {
          for(int j = 0 ; j < ingredients[i].size() ;j++ )
          {
              mp[recipes[i]].push_back(ingredients[i][j]);
          }
        }
        for(string st : recipes)
        {
           if(!vis.count(st))
              dfs(st ,mp , s);
        }
        vector<string> ans(res.begin() , res.end());
        return ans;
    }
};