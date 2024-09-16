
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector < int > times;
        for (int i = 0 ; i < timePoints.size(); i++)
        {
            int time = stoi(timePoints[i].substr(0, 2)) * 60;
            time += stoi(timePoints[i].substr(3, 2));
            if (time == 0)
                time = 24 * 60;
            times.push_back(time);
        }
        int ans = 1e9;
        for (int i = 0 ; i < times.size(); i++)
        {
            for (int j = i + 1; j < times.size(); j++)
            {
                ans = min(ans, abs(times[i] - times[j]));
                ans = min(ans, 24 * 60 - abs(times[i] - times[j]));
            }
        }
        return ans;
    }
};