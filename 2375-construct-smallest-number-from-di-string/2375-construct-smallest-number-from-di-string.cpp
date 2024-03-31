class Solution {
public:
    string smallestNumber(string pattern) 
    {
        string ans, mn;
        
        for (int i = 1 ; i <= pattern.size() + 1 ; i++)
        {
            ans.push_back(i + '0');
            mn.push_back('9');
        }
        
        do
        {

            bool valid = 1;

            for (int i = 0 ; i < pattern.size() ; i++)
            {
                if (pattern[i] == 'I')
                    valid &= (ans[i] < ans[i + 1]);
                else 
                    valid &= (ans[i] > ans[i + 1]);
            }

            if (valid)
                mn = min(mn , ans);

        } while(next_permutation(ans.begin() , ans.end()));

        return mn;
    }
};