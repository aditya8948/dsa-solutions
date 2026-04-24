class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int lCount = 0, rCount = 0, sCount = 0;
        for(char i : moves){
            if(i == 'R') rCount++;
            else if(i == 'L') lCount++;
            else sCount++;
        }
       int distance = max(rCount , lCount) - min(rCount , lCount);
       distance+= sCount;
       return distance ;
    }
};