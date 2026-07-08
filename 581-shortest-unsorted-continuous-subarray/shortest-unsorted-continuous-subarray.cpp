class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int rightMax = INT_MIN; int leftMin = INT_MAX;
        int left = -1 ; int right = -1;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            rightMax = max(rightMax, nums[i]);
            if(nums[i] < rightMax) right = i;
        }
        for(int i = n-1; i >= 0 ; i--){
            leftMin = min(leftMin , nums[i]);
            if(nums[i] > leftMin) left = i;
        }
        return right == -1 ? 0 : right - left + 1;
    }
};