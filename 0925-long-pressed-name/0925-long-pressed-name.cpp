class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if (name.size() > typed.size())
            return false;
        
        int j = 0;
        for (int i = 0 ; i < name.size() ;i++)
        {
            bool found = 0;
            while(j < typed.size() and name[i] == typed[j])
            { 
                j++ , found = 1;
                if (i + 1 and name[i + 1] == name[i])
                    break;
            }
            if (!found)
                return false;
        }
        return j == typed.size();
    }
};