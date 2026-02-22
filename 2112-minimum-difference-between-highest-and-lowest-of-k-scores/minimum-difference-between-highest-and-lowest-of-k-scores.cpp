class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin() ,nums.end());
        int highest = k-1 ;
        int lowest = 0;
        int ans = nums[highest]-nums[lowest] ;

        for(int i = 0 ; i+k-1 < nums.size() ;i++){
            lowest  = i;
            highest = i+k-1;
            int m = nums[highest]-nums[lowest];
            if(m < ans) ans = m;

        }
        return ans;
    }
};