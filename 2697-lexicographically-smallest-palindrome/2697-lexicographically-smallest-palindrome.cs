public class Solution {
    public string MakeSmallestPalindrome(string s) {
        int i = 0, j = s.Length - 1;
        StringBuilder sb = new StringBuilder(s);
        while(i < j)
        {
            char mn = (sb[i] < sb[j])? sb[i] : sb[j];
            sb[i] = mn;
            sb[j] = mn;
            i++;
            j--;
        }
        return sb.ToString();
    }
}