class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) 
    {
        vector < int > ans(prices.size(), -1);
        stack < int > st;
        for (int i = 0 ; i < prices.size(); i++)
        {
            while(st.size() and prices[i] <= prices[st.top()])
                ans[st.top()] = i, st.pop();
            st.push(i);
        }
        for (int i = 0 ; i < ans.size(); i++)
        {
            if (ans[i] == -1)
                ans[i] = prices[i];
            else
                ans[i] = prices[i] - prices[ans[i]];
        }
        return ans;
    }
};