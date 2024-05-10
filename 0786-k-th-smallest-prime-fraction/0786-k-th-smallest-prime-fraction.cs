public class Solution {
    public int[] KthSmallestPrimeFraction(int[] arr, int k) {
        /*
            a/b > c/d => a * d > c * b
        */
        List <double> list = new List<double>();
        
        Dictionary< double, KeyValuePair<int , int> > dic = 
            new Dictionary< double, KeyValuePair<int , int> >();
        
        for (int i = 0 ; i < arr.Length; i++)
        {
            for (int j = i + 1; j < arr.Length; j++)
            {
                list.Add(1.0 * arr[i] / arr[j]);
                dic.Add(1.0 * arr[i] / arr[j], new KeyValuePair<int, int>(arr[i], arr[j]));
            }
        }
        list.Sort();
        
        int[] ans = new int[2] {dic[list[k - 1]].Key, dic[list[k - 1]].Value};
        return ans;
        
    }
}