class Solution {
public:
    // This function finds the pivot index (largest element)
    int checkPartition(vector<int> &nums) {
        int low = 0;
        int high = nums.size() - 1;
        int lastIdx = high;   // index of last element (reference)

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // mid lies in second sorted part
            if (nums[mid] <= nums[lastIdx]) {
                high = mid - 1;
            }
            // mid lies in first part
            // check if this is the pivot
            else if (mid != lastIdx && nums[mid] > nums[mid + 1]) {
                return mid;
            }
            // move towards right
            else {
                low = mid + 1;
            }
        }
        return -1; // array is not rotated
    }
    
    int binarySearch(vector<int> &nums, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivotIndex = checkPartition(nums);

        //  array is not rotated
        if (pivotIndex == -1) {
            return binarySearch(nums, 0, n - 1, target);
        }
        //target lies in right sorted part
        else if (target <= nums[n - 1]) {
            return binarySearch(nums, pivotIndex + 1, n - 1, target);
        }
        //target lies in left sorted part
        else {
            return binarySearch(nums, 0, pivotIndex, target);
        }
    }
};
