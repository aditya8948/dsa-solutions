class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        // put all the positive number at there indexed position -1 
        for(int i = 0; i < n; i++){
            while(nums[i] <= n && nums[i] >= 1 && nums[i] != nums[nums[i] - 1]){
                swap(nums[i] , nums[nums[i] - 1]);
            }
         }

        // first first +ve no we is not present in nums is our ans else n+1
        for(int i = 0 ; i < n; i++) {
            if(nums[i] != i+1) return i+1;
        }
        
        return n+1;
    }
};