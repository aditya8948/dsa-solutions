class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<int> freq(10001,0);
        int i = 0 , j = 0 ;
        int ans = INT_MIN;
        int sum = 0 ;
        while(j < nums.size() ){
         if(freq[nums[j]] == 0){
            freq[nums[j]]++;
            sum+=nums[j];
            cout<<sum <<" ";
            j++;
         }
         else{
            sum-=nums[i];
            freq[nums[i]]--;
            i++;
         }
         ans = max(ans,sum);
    }
        return ans;
    }
};