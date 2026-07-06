class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        unsigned int mask = 1u <<31;

        while(mask){
            if(n & mask) count++;
            mask >>= 1;
        }
        return count;
    }
};