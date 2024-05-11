public class Solution {
    public int[][] ReconstructQueue(int[][] people) 
    {
        var list = people.ToList();
        
        list = list.OrderBy(a => a[0]).ThenBy(a => a[1]).ToList();
        
        int Count = list.Count();
        
        int[] preSame = new int[Count];
        Dictionary <int, int> dic = new Dictionary<int, int>();
        for (int i = 0 ; i < Count ; i++)
        {
            if (dic.ContainsKey(list[i][0]))
                preSame[i] = dic[list[i][0]];

            if (dic.ContainsKey(list[i][0]))
                dic[list[i][0]]++;
            else 
                dic.Add(list[i][0], 1);
        }
        
        for (int i = Count - 2; i >= 0 ; i--)
        {
            int rem = list[i][1] - preSame[i];
            // Swap rem steps to the right.
            for (int j = i + 1; rem > 0; j++)
            {
                // Swap j, j - 1
                int[] temp = list[j - 1];
                list[j - 1] = list[j];
                list[j] = temp;
                rem--;
            }
        }
        
        people = list.ToArray();
        return people;
    }
}