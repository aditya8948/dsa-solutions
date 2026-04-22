class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int countOnces  = 0 ; 
        int ans = INT_MAX;
        int n = nums.size();
        // counting total no. of one present in array 
        for(int i : nums) {
            if(i == 1) countOnces++;
        }

       int i = 0 , j = 0;
       int countZero = 0;
       while(j < 2*n){
        if(nums[j % n] == 0) countZero++;
        if(j-i+1 > countOnces){
            if(nums[i%n] == 0) countZero-- ;
            i++;
        }
        if(j-i+1 == countOnces){
            ans = min(ans,countZero);
        }
        j++;
       }
       return ans;
    }
};