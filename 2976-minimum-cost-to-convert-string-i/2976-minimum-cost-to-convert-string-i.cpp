class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector < vector < long long > > dis(26, vector < long long > (26, 1e18));

        for ( int i = 0 ; i < 26 ; i++)
            dis[i][i] = 0;

        for (int i = 0 ; i < original.size(); i++)
            dis[original[i] - 'a'][changed[i] - 'a'] = 1LL * cost[i];

        // Floyed Algorithm.
        for (int k = 0; k < 26; k++)
            for (int i = 0 ; i < 26 ; i++)
                for (int j = 0 ; j < 26; j++)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

        long long ans = 0;
        for (int i = 0 ; i < source.size() ; i++)
        {
            if(dis[source[i] - 'a'][target[i] - 'a'] == 1e18)
                return -1;
            ans += dis[source[i] - 'a'][target[i] - 'a'];
        }

        return ans;
    }
};