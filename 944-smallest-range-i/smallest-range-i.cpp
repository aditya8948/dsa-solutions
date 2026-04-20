class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int minimum = INT_MAX;
        int maximum = INT_MIN;
        for(int i = 0 ; i < nums.size() ;i++){
            if(minimum > nums[i]) minimum= nums[i];
            if(maximum < nums[i]) maximum= nums[i];
        }
        return max(0,(maximum-k)-(minimum+k));
    }
};