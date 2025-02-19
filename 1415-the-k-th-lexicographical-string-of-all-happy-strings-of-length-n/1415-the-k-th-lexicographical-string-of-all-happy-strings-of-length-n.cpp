class Solution {
private: 
    vector < string > list;
    void generate(string &path, int n)
    {
        if (path.size() == n)
        {
            list.push_back(path);
            return;
        }

        for (char c = 'a'; c <= 'c'; c++)
        {
            if (path.size() and path.back() == c)
                continue;
            path.push_back(c);
            generate(path, n);
            path.pop_back();
        }
    }
public:
    string getHappyString(int n, int k) {
        string s;
        generate(s, n);
        if (list.size() < k)
            return "";
        return list[k - 1];
    }
};