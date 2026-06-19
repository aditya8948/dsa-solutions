class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        vector<int> res(nums1.size(), -1);

        for(int i = 0; i < nums1.size(); i++) {

            int index = -1;

            for(int j = 0; j < nums2.size(); j++) {
                if(nums2[j] == nums1[i]) {
                    index = j;
                    break;
                }
            }

            for(int k = index + 1; k < nums2.size(); k++) {
                if(nums2[k] > nums1[i]) {
                    res[i] = nums2[k];
                    break;
                }
            }
        }

        return res;
    }
};