class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int a = 0 ;
        vector <int> v;
        for (int i = 0 ; i < pushed.size() ; i++)
        {
            v.push_back(pushed[i]);
            while(v.size() and v.back() == popped[a])
                v.pop_back(),  a++;
        }
        return v.empty();
    }
};