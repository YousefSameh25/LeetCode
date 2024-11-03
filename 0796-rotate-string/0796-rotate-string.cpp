class Solution {
public:
    bool rotateString(string s, string goal) {
        queue< char > q, q2;
        for (auto c: s)
        {
            q.push(c);
        }
        for (auto c: goal)
        {
            q2.push(c);
        }
        int n = q.size();
        while(n--)
        {
            if (q == q2)
                return 2;
            q.push(q.front());
            q.pop();
        }
        return false;
    }
};