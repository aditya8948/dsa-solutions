class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans = 0 ;
        int n = colors.size();
         for(int j = n-1; j > 0 ; j--){
            if(colors[j] != colors[0]){
                ans = j;
                break;
            }
         }

         for(int i = 0 ; i < n-1; i++){
            if(colors[i] != colors[n-1]){
                ans = max (ans , n-i-1);
                break;

            }
         }
         return ans;
    }
};