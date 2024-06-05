class Solution {
public:
    vector <int> vis;
    void dfs (int room, vector<vector<int>>& rooms)
    {
        vis[room] = 1;
        for (auto roomkey : rooms[room])
        {
            if (vis[roomkey])
                continue;
            dfs(roomkey, rooms);
        }
    }
    
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vis.resize(rooms.size(), 0);
        dfs(0, rooms);
        
        bool ok = 1;
        for (int i = 0 ; i < rooms.size(); i++)
            ok &= vis[i];
        
        return ok;
        
    }  
};