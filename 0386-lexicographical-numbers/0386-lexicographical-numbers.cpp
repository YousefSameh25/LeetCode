class Solution {
public:
    vector<int> lexicalOrder(int n) {
        /*
           ex) 1003
           1 (0 -> 9)
           10 (0 -> 9)
           100 (0 -> 9)
           1000 (0 -> 3)

           2 (0 -> 9)
           20 (0 -> 9)
           ..
        */
        vector < int > ans;
        int num = 1;
        while(num <= 9)
        {
            int p = 1;
            while(p * num <= n)
                ans.push_back(num * p), p *= 10;
            p = 10;
            while(num * p <= n)
            {
                
                for (int d = 1 ; d <= 9; d++)
                {
                    if (num * p + d > n)
                        break;
                    ans.push_back(num * p + d);
                }
                p *= 10;
            }
            num++;
        }
        return ans;
    }
};