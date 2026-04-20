class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int i = 0 ;
        int j = n-1;
        int ans = 0;
        while(i < n-1 && j > i){
            if(colors[i] == colors[j]){
                j--;
            }
            else{
                ans = max(ans , j-i);
                i++;
                j = n-1;
            }
        }
        return ans;
    }
};