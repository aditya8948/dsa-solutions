class Solution {
public:
    int binaryGap(int n) {
        long mask = (1L << 31);
        int maxDist = 0;
        int currentDistance = -1;   // -1 means no '1' seen yet

        while (mask) {
            if (n & mask) {
                if (currentDistance != -1)  // not the first '1'
                    maxDist = max(maxDist, currentDistance+1);

                currentDistance = 0; // reset after seeing '1'
            }
            else if (currentDistance != -1) {
                currentDistance++;   // count distance between 1s
            }

            mask >>= 1;  // move mask
        }
        return maxDist;
    }
};