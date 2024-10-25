class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) 
    {
        sort (folder.begin(), folder.end());
        vector < string > ans;
        ans.push_back(folder[0]);
        for (int i = 1 ; i < folder.size() ; i++)
        {
            string temp = folder[i].substr(0, ans.back().size());

            int j = ans.back().size();

            while(j < folder[i].size() and folder[i][j] != '/')
                temp.push_back(folder[i][j]), j++;

            if (temp != ans.back())
                ans.push_back(folder[i]);
        }
        return ans;
    }
};