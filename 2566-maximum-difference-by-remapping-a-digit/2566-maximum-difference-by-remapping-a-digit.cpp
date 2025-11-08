class Solution {

private: 
    int calculateBest(int num, char usedValue)
    {
        string numStr = to_string(num);
        int val = -1;
        for (int i = 0 ;  i < numStr.size(); i++)
        {
            if (numStr[i] == usedValue)
                continue;
            
            if (val == -1)
            {
                val = numStr[i] - '0';
                numStr[i] = usedValue;
            }
            else if (val == numStr[i] - '0')
            {
                numStr[i] = usedValue;
            }
        }
        return stoi(numStr);
    }

public:
    int minMaxDifference(int num) {
        return calculateBest(num, '9') - calculateBest(num, '0');
    }
};