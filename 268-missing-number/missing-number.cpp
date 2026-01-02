class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int totalSum = n*(n+1)/2;      // total sum of  0 to n
        int sum =0 ;
        for(int i = 0 ; i < n ; i++){
            sum+=nums[i];             // sum of nums
        }
        return totalSum-sum;         // this gives miss value

    }
};