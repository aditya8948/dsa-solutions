class Solution {
public:
    int checkPartition(vector<int> &nums){
        int low  = 0 ; int high = nums.size()-1;
        int n = high ;
        while(low <= high){
            int mid = low + (high - low) / 2;
             if(nums[mid] <= nums[n])  high=mid-1;
             else if(mid != n && nums[mid] > nums[mid+1]) return mid;
             else low = mid +1;
        }
        return -1;
    }

    int binarySearch(vector<int> &nums , int low , int high , int target){
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target) return mid;
            else if( nums[mid] > target) high = mid - 1;
            else low = mid +1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = checkPartition(nums);

        if(pivot == -1){
           return  binarySearch(nums,0,nums.size()-1,target);
        }
        else if(target <= nums[n-1]){
           return   binarySearch(nums,pivot+1,nums.size()-1,target);
        }
        else{
          return    binarySearch(nums,0,pivot,target);
        }
        
    }
};