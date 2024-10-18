class Solution {
private:
    unordered_map < char , vector <char> > mp;
    vector < string > ans;
public:
    void solve(int i, string &s, string &path)
    {
        if (i == s.size())
        {
            if (path.size())
                ans.push_back(path);
            return;
        }

        for (auto &it : mp[s[i]])
        {
            path.push_back(it);
            solve(i + 1, s, path);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        char c = 'a', cnt = 0, num = '2';
        while (c <= 'z')
        {
            mp[num].push_back(c);
            c++, cnt++;
            if ((num == '7' or num == '9') and cnt % 4 == 0)
            {
                cnt = 0;
                num++;
            }
            else if (cnt % 3 == 0 and num != '7' and num != '9')
            {
                cnt = 0;
                num++;
            }
        }

        string path;
        solve(0, digits, path);
        return ans;
    }
};