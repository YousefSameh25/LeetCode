class Solution {
public:
    string nearestPalindromic(string s) {
        int n = s.size();
        if(n == 1) return to_string((s[0]-'0')-1);  // if single digit return 1 number lesser
        else 
        {
            long long original = stoll(s); // convert string to long long so we can add or subtract easily
            long long ans = pow(10, n-1) -1; // minimum palindrome possible for ans
            long long tmp = pow(10, n) +1; // maximum palindrome possible for ans
            ans = (abs(tmp - original)) < (abs(ans - original)) ? tmp : ans; // compare between the above two palindrome


            // to make other palindrome changing the middle digits will be optimum
            int idxToChange = (n+1)/2; // find the middle index
            string firstHalf = s.substr(0, idxToChange); // find first half string
            long long changesInMiddle = stoll(firstHalf); // convert string to ll


            // there are three cases either decrease the middle by 1, or increase by 1, or do nothing

            // case 1, increase by 1
            firstHalf = to_string(changesInMiddle + 1); // increase the number by 1, and convert to string
            string palindrome = firstHalf; 
            for(int i = n/2 -1; i >= 0; i--) palindrome += firstHalf[i]; // make palindrome of with help of first half number

            tmp = stoll(palindrome); // again convert to long long, to compare with original number
            if(abs(original - tmp) < abs(original - ans)) ans = tmp; // if difference is smaller, make it answer
            else if(abs(original - tmp) == abs(original - ans)) // if difference is same, take the smaller one
            {
                ans = tmp < ans ? tmp : ans;
            }

            
            // case 2, decrease by 1, all the steps are same as case 1
            firstHalf = to_string(changesInMiddle - 1);
            palindrome = firstHalf; 
            for(int i = n/2 -1; i >= 0; i--) palindrome += firstHalf[i];

            tmp = stoll(palindrome);
            if(abs(original - tmp) < abs(original - ans)) ans = tmp;
            else if(abs(original - tmp) == abs(original - ans))
            {
                ans = tmp < ans ? tmp : ans;
            }


            // case 3, when we are not doing anything, just make the replica of first half
            firstHalf = to_string(changesInMiddle);
            palindrome = firstHalf; 
            for(int i = n/2 -1; i >= 0; i--) palindrome += firstHalf[i];

            tmp = stoll(palindrome);

            if(tmp == original) return to_string(ans); // the palindrome should not be same as original number given

            if(abs(original - tmp) < abs(original - ans)) ans = tmp;
            else if(abs(original - tmp) == abs(original - ans))
            {
                ans = tmp < ans ? tmp : ans;
            }
            return to_string(ans);
        }
    }
};