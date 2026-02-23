class Solution {
public:
// here we are using the reverse lookup approach instead of chasing every pair contribution 
// we will look for each bit contribution
// the total  contribution of each bit will be => num of '1'(on bit) * number of '0'(off bit)

    int totalHammingDistance(vector<int>& nums) {
        long mask = (1L << 31);
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < 32; i++){
            int count = 0;
            for(int j = 0; j < n ; j++){
                if(nums[j] & mask)  count++;   // count total no. of 1 in particular bit level
            }
            ans+= count * (n-count);     // n-count => total no. of zero
            mask >>= 1;                 // rightshift mask 
        }
        return ans;
    }
};