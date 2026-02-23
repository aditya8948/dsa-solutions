class Solution {
public:
    int hammingDistance(int x, int y) {
        long mask = (1L << 31);
        int count = 0;
        while(mask){
            if((mask & x) != (mask & y)) count++;// check the bit at each level of both x and y 

            mask >>= 1;    // right the mask value 
        }
        return count;
    }
};