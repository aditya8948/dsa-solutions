class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, count = 0;
        for(int i : nums){
            if(i) count++;
            else count = 0;
            ans = max(ans , count);
        }
        return ans;
    }
};