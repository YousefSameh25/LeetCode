class Solution {
public:
    
    vector <char> CntD (int n)
    {
        vector < char > v;
        while(n)
            v.push_back((n % 10) + '0'), n /= 10;
        
        reverse(v.begin(), v.end());
        return v;
    }
    
    int compress(vector<char>& chars) {
        
        int ans = 0;
        vector < char > ret;
        for (int i = 0; i < chars.size(); )
        {
            int j = i;
            char c = chars[j];
            int cnt = 0;
            while(j < chars.size() and c == chars[j])
                j++, cnt++;
                        
            if (cnt == 1)
            {
                ans++;
                ret.push_back(c);
            }
            else 
            {
                ans++;
                vector < char> tmp = CntD(cnt);
                ans += tmp.size();
                
                ret.push_back(c);
                for (auto it : tmp)
                    ret.push_back(it);
            }  
            
            if (i == j)
                i++;
            else
                i = j;
        }
        
        chars = ret;
        
        return ans;
        
    }
};