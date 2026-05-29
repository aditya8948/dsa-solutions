class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
      for(int i = 0; i < nums.size() ; i++){
        int num=0;
        while(nums[i] > 0){
            num+= nums[i]%10;
            nums[i] = nums[i] / 10;
        }
        ans = min(ans , num);
      }

    
      return ans;
    }
};