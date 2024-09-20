class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();   
        int i = 0, j = n - 1;
        
        // Find the longest palindrome starting from the first character
        while (j >= 0) 
        {
            if (s[i] == s[j]) 
            {
                i++;  
            }
            j--;  
        }
        
        // If the entire string is already a palindrome
        if (i == n) 
        {
            return s;
        }
        
        // Create the suffix (part that isn't a palindrome at the start)
        string suffix = s.substr(i);
        
        // Reverse the suffix to add at the beginning
        reverse(suffix.begin(), suffix.end());
        
        // Recursive call to find the shortest palindrome for the remaining string
        return suffix + shortestPalindrome(s.substr(0, i)) + s.substr(i);
    }
};