class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;
        for(int i=0; i<n; i++){
            int num=nums[i];
            if(num==k){
                cnt++;
            }
            for(int j=i+1; j<n; j++){
                num=lcm(num, nums[j]);
                if(num==k){
                    cnt++;
                }
                if(num>k){
                    break;
                }
            }
        }
        return cnt;
    }
};