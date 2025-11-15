class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        map < int , int > mp;

        for (int i = 0 ; i < clips.size() ; i++)
            mp[clips[i][0]] = max(mp[clips[i][0]], clips[i][1]);

        if (!mp.count(0))
            return -1;

        int l = -1, r = -1, ans = 0;
        for (auto &it : mp)
        {
            //cout << it.first << " " << it.second << endl;
            if (l == -1  && r == -1)
            {
                l = it.first;
                r = it.second;
                ans++;
            }
            // In range -> skip it.
            else if (it.first >= l && it.second <= r)
                continue;
            // New range here.
            else if (it.first < r && it.second > r)
            {
                int tempL = r, tempR = it.second;
                mp[tempL] = max(mp[tempL], tempR);
            }
            // take it
            else if (it.first == r || it.first == r + 1)
            {
                r = it.second;
                ans++;
            } else
                return -1;

            if (r >= time)
                break;
        }
        //cout << l << "-" << r <<endl;
        return r >= time ? ans : -1;
    }
};