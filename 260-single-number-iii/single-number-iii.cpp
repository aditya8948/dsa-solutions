class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
      int totalXOR = 0;
    //   computing total xor and we get the xor of that two unique element 
      for(int i = 0 ; i < nums.size(); i++){
        totalXOR ^= nums[i];
      }
   // find least significant bit 
     int mask = 1;
     for(int i = 0 ; i < 32 ; i++){
        if( !(mask & totalXOR) )  mask <<= 1;
        else break;
     }

    int val1 = 0;
    for(int i = 0 ; i < nums.size(); i++){
        if(mask & nums[i])
            val1^= nums[i];
    }
 
    int val2 = (totalXOR ^ val1);

    return {val1,val2};

    }
};



/*
  vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            int count = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    count++;
                }
            }
            if (count == 1) {
            ans.push_back(nums[i]);
            }
        }

        return ans;
        */