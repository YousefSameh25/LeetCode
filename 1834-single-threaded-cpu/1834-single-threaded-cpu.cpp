class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        for (int i = 0 ; i < tasks.size() ; i++)
            tasks[i].push_back(i);
        
        sort(tasks.begin(), tasks.end());
        
        long long time = 0, i = 0;
        
        priority_queue <vector <int>> pq;
        
        vector <int> ans (tasks.size());
        
        int pos = 0;
        while(i < tasks.size() or pq.size())
        {
            if (!pq.size())
            {
                time = tasks[i][0] + tasks[i][1];
                ans[pos++] = tasks[i][2];
                i++;
            }
            else 
            {
                auto top = pq.top();
                pq.pop();
                time += -top[0];
                ans[pos++] = -top[1];
            }
            for (int j = i; j < tasks.size() and tasks[j][0] <= time; j++)
                pq.push({-tasks[j][1], -tasks[j][2]}), i++;
        }
        return ans;
    }
};