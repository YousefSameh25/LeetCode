class Solution {
public:
    long long minimumSteps(string s) {
        /*
            01234
            11001

            [1, 0]
        */
        queue < int > q;
        bool z = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            z |= s[i] == '0';
            if (s[i] == '1' and z)
                q.push(i);
        }

        long long ans = 0;
        for (int i = s.size() - 1; i >= 0 and q.size(); i--)
        {
            if (s[i] == '1')
                continue;
            swap(s[i], s[q.front()]);
            ans += 1LL * (i - q.front());
            q.pop();
        }
        return ans;
    }
};