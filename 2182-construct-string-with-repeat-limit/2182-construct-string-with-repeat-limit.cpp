class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string result;
        int currentCharIndex = 25, cnt = 0; 
        while (currentCharIndex >= 0) 
        {
            if (freq[currentCharIndex] == 0) {
                currentCharIndex--;
                continue;
            }

            
            result.push_back('a' + currentCharIndex);
            freq[currentCharIndex]--, cnt++;

            if (freq[currentCharIndex] == 0)
            {
                cnt = 0;
                continue;
            }

            if (cnt == repeatLimit)
            {
                int smallerCharIndex = currentCharIndex - 1;
                while (smallerCharIndex >= 0 && freq[smallerCharIndex] == 0) {
                    smallerCharIndex--;
                }
                if (smallerCharIndex < 0) {
                    break;
                }
                result.push_back('a' + smallerCharIndex);
                freq[smallerCharIndex]--;
                cnt = 0;
            }
        }

        return result;
    }
};