class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count1 =0 , count2 = 0, maj1 = NULL, maj2 = NULL;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == maj1) count1++;
            else if(nums[i] == maj2) count2++;
            else if(count1 == 0) {
                maj1 = nums[i];
                count1++;
            }
            else if(count2 == 0){
                maj2 = nums[i];
                count2++;
            }
            else{
                count1--;
                count2--;
            }

        }

        vector<int> res;
        int freq1 = 0;
        int freq2 = 0;

        for(int num: nums){
            if(num == maj1) freq1++;
            if(num == maj2) freq2++;
        }
        
        if(freq1 > floor(n/3)) res.push_back(maj1);
        if(freq2 > floor(n/3) && maj2 != maj1) res.push_back(maj2);

        return res;
    }
};