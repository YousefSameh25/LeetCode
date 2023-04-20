class Solution {
public:
    bool sumGame(string num) 
    {
        int l = 0 , r = 0 , sl = 0 , sr = 0;
        for (int i = 0 ; i < num.size() ; i++)
        {
            if (num[i] =='?')
                (i < num.size() / 2)? l++ : r++;
            else
                (i < num.size() / 2)? sl += (num[i] - '0') : sr += (num[i] - '0');
        }
        if (l == r)
            return (sl != sr);
        int rem = max (l , r) - min (l , r);
        
        if (l > r)
            swap(l , r) , swap(sl , sr);
        
        // Alice add 9 every time
        if (((rem + 1) / 2) * 9  + sr > sl)
            return true;
        // Bob add 9 every time
        if ((rem / 2) * 9 + sr < sl)
            return true;
        
        return false;
    }
};