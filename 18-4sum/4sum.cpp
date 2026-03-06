class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> result;
        int n = nums.size();
        //picking first element 
        for(int i = 0 ; i < n-1; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue; // avoid repeated number 

            for(int j = i+1 ; j < n-1 ; j++){
                if(j > i+1 && nums[j]==nums[j-1]) continue; 

                long rem =  (long long)target - (nums[i]+nums[j]);
                int p1 = j+1 ;
                int p2 = n-1;
                while(p1 < p2){
                    if(nums[p1] + nums[p2] < rem) p1++;
                    else if(nums[p1] + nums[p2] > rem) p2--;
                    else {
                        result.push_back({nums[i],nums[j],nums[p1],nums[p2]});
                        if(nums[p1] == nums[p2]) break;
                        int x =nums[p1];
                        int y = nums[p2];
                        while(nums[p1] == x) p1++;
                        while(nums[p2] == y) p2--;
                    }

                }
            }
        }
        return result;
    }
};