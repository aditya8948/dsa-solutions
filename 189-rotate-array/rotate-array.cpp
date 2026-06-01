class Solution {
public:
    void reverseArr(vector<int>& nums, int i , int j){
        while(i < j){
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            i++;j--;
        }
        
        
    }
    
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k % size;
        reverseArr(nums, 0, size-k-1);

        reverseArr(nums, size-k, size-1);
        reverseArr(nums, 0, size-1);

    }
};