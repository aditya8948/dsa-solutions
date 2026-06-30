class Solution {
public:
    int calculateMaxArea(vector<vector<int>> & heights ,int row){

        int n = heights[0].size();
        vector<int>nse(n);
        vector<int>pse(n);
        stack<int> stk;
        // precompute nse
        for(int i = 0; i < n; i++){
            while(!stk.empty() && heights[row][i] < heights[row][stk.top()]){
                nse[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        while(!stk.empty()) {
            nse[stk.top()] = n;
            stk.pop();
        }

        // precompute pse
        for(int i = n-1; i >= 0; i--){
            while(!stk.empty() && heights[row][i] <= heights[row][stk.top()]){
                pse[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        while(!stk.empty()) {
            pse[stk.top()] = -1;
            stk.pop();
        }

        // logic 
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans , (nse[i] - pse[i] - 1) * heights[row][i]);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int row = matrix.size();
        int col = matrix[0].size();

        // creating histogram matrix
        vector<vector<int>> heights(row, vector<int>(col,0));

        for(int i = 0; i < col; i++){
            heights[0][i] = matrix[0][i] - '0';
            for(int j = 1; j < row; j++){
                if(matrix[j][i] == '1'){
                    heights[j][i] = heights[j-1][i]+1;
                }
            }
        }
      int finalAns = 0;
      for(int i = 0 ; i < row; i++){
        finalAns = max(finalAns , calculateMaxArea(heights , i));
      }
      return finalAns;
    }
};