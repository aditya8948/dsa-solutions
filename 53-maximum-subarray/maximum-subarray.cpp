class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0];     // stores maximum subarray sum found so far
        int currentSum = 0;       // stores sum of current subarray

        for(int i = 0; i < nums.size(); i++) {

            currentSum += nums[i];      // add current element to running sum

            result = max(result, currentSum); // update result 

            if(currentSum < 0) {   // if current sum become negative ,
            currentSum = 0;        // that subarray cant contribute for largest sum
            }
        }
        return result;  
    }
};
