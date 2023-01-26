class Solution {
public:
    vector<string> watchedVideosByFriends (vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) 
    {
        vector <int> lvl (101 , 0) , vis(101 , 0);
        queue <int> q;
        vis [id] = 1;
        q.push(id);
        while (q.size())
        {
            int t = q.front();
            q.pop();
            for (auto child : friends[t])
            {
                if (vis[child])
                    continue;
                vis[child] = 1;
                lvl[child] = lvl[t] + 1;
                q.push(child);
            }
        }
        unordered_map <string  , int> f;
        vector <string> ret;
        for (int i = 0 ; i <= 100 ; i++)
        {
            if (lvl[i] == level)
            {
                for (auto video : watchedVideos[i])
                {
                    if (f[video] == 0)
                        ret.push_back(video);
                    f[video]++;
                }
            }
        }
      sort (ret.begin() , ret.end() , [&](string  a, string b) 
      { 
          
         if (f[a] == f[b])
         {
             return a < b;
         }
         else 
         {
             return (f[a] < f[b]);
         }
      });
        return ret;
    }
};