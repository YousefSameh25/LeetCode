class Solution {
public:
    bool fun (string & a , string & b)
    {
        return (a + b > b + a);
    }
    string largestNumber(vector<int>& nums)
    {
        vector < string > v;
        bool z = 1;
        for (auto &it : nums)
        {
            z &= (it == 0);
            v.push_back(to_string(it));
        }
        
        if (z)
            return "0";
        
        sort(v.begin() , v.end() , [] (string & a, string & b)
        { 
            return a + b > b + a; 
        });
        
        string ans;
        for (auto &st : v)
            ans.append(st);

        return ans;
    }
};