public class Solution {
    public int LeastInterval(char[] tasks, int n) 
    {
        int[] freq = new int[26];
        int mxFreq = 0;
        for (int i = 0 ; i < tasks.Length ; i++)
        {
            freq[tasks[i] - 'A']++;
            mxFreq = Math.Max(mxFreq, freq[tasks[i] - 'A']);
        }
        
        int SameFreqAsMax = 0;
        for (int i = 0 ; i < 26 ; i++)
            if (freq[i] == mxFreq)
                SameFreqAsMax++;
        
       return Math.Max((n + 1) * mxFreq - ((n + 1) - SameFreqAsMax), tasks.Length);
    }
}