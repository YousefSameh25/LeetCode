class Solution {
public:
/*
    North: y + k

*/
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        set < pair < int , int >> obstacle;

        for (auto &it : obstacles)
            obstacle.insert({it[0], it[1]});

        int ans = 0;
        int x = 0, y = 0;
        //                   N  E  S  W
        vector < int > dx = {0, 1, 0, -1};
        vector < int > dy = {1, 0, -1, 0};
        int ptr = 0;
        for (auto &it : commands)
        {
            if (it < 0)
            {
                it == -1?  ptr++: ptr--;
                ptr += 4;
                ptr %= 4;
            }
            else 
            {
                while(it--)
                {
                    int Newx = x + dx[ptr];
                    int Newy = y + dy[ptr];
                    if (obstacle.count({Newx, Newy}))
                        break;
                    x = Newx;
                    y = Newy;
                    ans = max(ans, y * y  + x * x);
                }
            }
        }
        return ans;
    }
};