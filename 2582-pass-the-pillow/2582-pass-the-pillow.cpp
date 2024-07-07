class Solution {
public:
    int passThePillow(int n, int time) 
    {
        int r = time / (n - 1);
        int rem = time - r * (n - 1);
        if (r & 1)
            return n - rem;
        else
            return 1 + rem;
    }
};