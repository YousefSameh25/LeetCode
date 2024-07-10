class Solution {
public:
    int minOperations(vector<string>& logs) {
        int dir = 0;
        for (auto it : logs)
        {
            if (it == "./")
               continue;
            (it == "../")? dir--: dir++;
            if (dir < 0) dir = 0;
        }
        return abs(dir);
    }
};