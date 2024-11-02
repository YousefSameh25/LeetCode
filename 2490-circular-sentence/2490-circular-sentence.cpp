class Solution {
public:
    bool isCircularSentence(string sentence) {
        bool ok = 1;
        for (int i = 0 ; i < sentence.size() ;i++)
        {
            if(sentence[i] == ' ')
                ok &= (sentence[i - 1] == sentence[i + 1]);
        }
        ok &= sentence[0] == sentence.back();
        return ok;
    }
};