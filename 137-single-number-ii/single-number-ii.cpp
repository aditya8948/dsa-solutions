class Solution {
public:
    // here we are playing at bit level , 
    // logic => at every level of bit when we count the on switch it will be multiple of 3 
    // becaue every elemnt coms three time except one element , if the count is not multiple of three
    // that means that single bit constribute there and we add it to our ans
    int singleNumber(vector<int>& nums) {
        long mask = (1L << 31);        
        int ans = 0;
        for(int i = 0 ; i < 32 ; i++){     // check for each bit 
            int count = 0;
            for(int j = 0 ; j < nums.size() ; j++){  // check for each number 
                if(nums[j] & mask) count++;
            }
            if(count % 3 != 0) ans+=mask;      // if the single bit is on at that bit level
            mask >>= 1;                    // right shift to check next bit
        }
        return ans;
    }
};