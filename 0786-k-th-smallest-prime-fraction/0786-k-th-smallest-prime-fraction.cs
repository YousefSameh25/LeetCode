public class Solution {
    public int[] KthSmallestPrimeFraction(int[] arr, int k) {
        /*
            a/b > c/d => a * d > c * b
        */
        List <KeyValuePair<double, KeyValuePair<int , int>>> list = 
            new List<KeyValuePair<double, KeyValuePair<int , int>>>();
        
        for (int i = 0 ; i < arr.Length; i++)
        {
            for (int j = i + 1; j < arr.Length; j++)
            {
                list.Add( 
                new KeyValuePair<double, KeyValuePair<int , int>>((1.0 * arr[i] / arr[j]),
                new KeyValuePair<int , int>(arr[i], arr[j]))
                );
            }
        }
        list = list.OrderBy(r => r.Key).ToList();
        
        int[] ans = new int[2] {list[k - 1].Value.Key, list[k - 1].Value.Value};
        return ans;
        
    }
}