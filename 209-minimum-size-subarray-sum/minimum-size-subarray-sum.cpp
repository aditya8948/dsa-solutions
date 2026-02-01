class Solution {
public:
    bool ispossible(int k, vector<int>& nums, int target) {
        if (k == 0) return false;  // jab saare elemnt target se bde ho k =0
        int sum = 0;
        for (int i = 0; i < k; i++) sum += nums[i];
        if (sum >= target) return true;

        int left = 0;
        for (int right = k; right < nums.size(); right++) {
            sum -= nums[left];
            sum += nums[right];
            left++;

            if (sum >= target) return true;
        }
        return false;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 1;
        int high = nums.size();
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (ispossible(mid, nums, target)) {
                ans = mid;
                high = mid - 1;   // try smaller
            } else {
                low = mid + 1;    // need bigger window
            }
        }
        return ans;
    }
};
