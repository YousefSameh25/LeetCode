
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector < int > times;
        for (int i = 0 ; i < timePoints.size(); i++)
        {
            int time = stoi(timePoints[i].substr(0, 2)) * 60;
            time += stoi(timePoints[i].substr(3, 2));
            if (time == 0)
                time = 60 * 24;
            times.push_back(time);
        }
        sort(times.begin(), times.end());
        int ans = 24 * 60 - (times.back() - times[0]);
        for (int i = 1 ; i < times.size(); i++)
            ans = min(ans, abs(times[i] - times[i - 1]));
        
        return ans;
    }
};