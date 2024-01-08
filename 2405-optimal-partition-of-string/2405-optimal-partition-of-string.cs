public class Solution {
    public int PartitionString(string s) {
        var st = new SortedSet<char>();
        int sub = 0;
        
        foreach (char c in s)
        {
            if (st.Contains(c))
            {
                sub++;
                st.Clear();
                st.Add(c);
            } 
            else 
                st.Add(c);
        }
        return sub + ((st.Count > 0)? 1 : 0);
    }
}