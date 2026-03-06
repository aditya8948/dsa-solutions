class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i < nums.size() ; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int rem = -1 * nums[i];
            int p1 = i+1 , p2 = nums.size()-1;

            while(p1 < p2){
                if(nums[p1] + nums[p2] <  rem) p1++;
                else if(nums[p1] + nums[p2] > rem) p2--;
                else {
                    result.push_back({nums[i],nums[p1],nums[p2]});
                    if(nums[p1] == nums[p2]) break;
                    int x = nums[p1] , y = nums[p2];
                    while(nums[p1] == x) p1++;
                    while(nums[p2] == y) p2--;
                }
            }
        }
        return result;
    }
};