class Solution {
public:
   int  ispossible(vector<int>& position , int m , int mid){
       int  iscount = 1;
        int prev = position[0];
        for(int i = 1 ; i < position.size() ; i++){
            if(position[i] - prev >= mid) {
                iscount++;
                prev = position[i];
            }
        }
        if(m <= iscount) return true;
        else return false;
    }
    int maxDistance(vector<int>& position, int m) {
    sort(position.begin(), position.end());

        int low = 0 ;
        int high = INT_MAX;
        while(low <= high){
            int mid = low +(high-low)/2;
            bool r1 = ispossible(position,m,mid);
            if(!r1) high = mid - 1;
            else {
                bool r2 = ispossible(position,m,mid+1);
                if(!r2) return mid;
                else low =mid+1;
            }
        }
        return -1;
    }

};