class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        // left = smallest value, right = largest value
        int left = nums[0], right = nums[0];

        // array ka min aur max nikal rahe hain
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < left)  left = nums[i];
            if(nums[i] > right) right = nums[i];
        }

        // value pe binary search
        while(left < right) {

            int mid = left + (right - left + 1 ) / 2;
            int count = 0;

            // count kar rahe hain kitne numbers >= mid hain
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] >= mid)
                    count++;
            }

            /*
              agar mid se bade ya equal numbers >= k hain
              matlab kth largest mid ya usse bada ho sakta hai
            */
            if(count >= k) {
                left = mid ;   // right side jao
            }
            /*
              agar mid se bade numbers kam hain
              matlab answer mid se chhota hoga
            */
            else {
                right = mid -1;     // left side jao
            }
        }

        // left ek step aage chala jata hai
        return left ;
    }
};
