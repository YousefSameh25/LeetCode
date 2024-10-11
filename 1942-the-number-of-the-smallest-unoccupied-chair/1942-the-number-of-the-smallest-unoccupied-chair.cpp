class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {

        set < int > avi;
        for (int i = 0 ; i < times.size(); i++)
        {
            avi.insert(i);
            times[i].push_back(i);
        }

        sort(times.begin(), times.end());
        
        //                     time, chair
        priority_queue < pair < int , int >> pq;
        for ( int i = 0 ;  i < times.size() ; i++)
        {
            while(pq.size() and -pq.top().first <= times[i][0])
                avi.insert(pq.top().second), pq.pop();

            int ans = *avi.begin();
            pq.push({-times[i][1], *avi.begin()});
            avi.erase(avi.begin());

            if (times[i][2] == targetFriend)    
                return ans;
        }
        return 0;
    }
};