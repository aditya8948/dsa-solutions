class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for(int j : nums){
            if(j != val){
                swap(nums[i],j);
                i++;
            }
        }
        return i;
    }
};