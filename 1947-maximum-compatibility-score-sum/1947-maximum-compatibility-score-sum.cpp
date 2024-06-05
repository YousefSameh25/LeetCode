class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        
        
        sort(mentors.begin(), mentors.end());
        
        int mx = 0;
        do
        {
            int temp = 0;
            for (int i = 0 ; i < students.size(); i++)
            {
                for (int j = 0 ; j < students[0].size(); j++)
                {
                    temp += students[i][j] == mentors[i][j];
                }
            }
            mx  =max(mx , temp);
            
        } while(next_permutation(mentors.begin(), mentors.end()));
        
        return mx;
    }
};