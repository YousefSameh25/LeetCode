class Solution 
{
public:
    string repeatLimitedString(string s, int repeatLimit) 
    {
        vector < int > cnt(26, 0);
        for (auto &it : s)
            cnt[it - 'a']++;

        priority_queue < pair < char, pair < int , int > >> pq;
        for ( int i = 0 ; i < 26; i++)
        {
            if (cnt[i])
                pq.push({i + 'a', {cnt[i], repeatLimit}});
        }

        string ans;
        while(pq.size())
        {
            auto it = pq.top();
            pq.pop();
            if (it.second.second)
            {
                it.second.second--;
                ans.push_back(it.first);
                it.second.first--;
                if (it.second.first)
                    pq.push(it);
            }
            else
            {
                if (!pq.size())
                    break;

                auto it2 = pq.top();
                pq.pop();

                it2.second.first--;
                ans.push_back(it2.first);

                if (it2.second.first)
                    pq.push(it2);

                it.second.second = repeatLimit;

                pq.push(it);  
            }
        }
        return ans;
    }
};