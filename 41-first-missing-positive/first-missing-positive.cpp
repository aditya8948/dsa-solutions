class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            // swap unitl no. is valid no not get  to its orignal position
            while(nums[i] <= n && nums[i] >= 1 && nums[i]!= nums[nums[i] - 1]) { 
                 swap(nums[i], nums[nums[i] - 1]);
            }

        }
        // check which value is not eual to i+1(positive integer)
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] != i+1) return i+1;
        }
        return n+1;
    }
};
