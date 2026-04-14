class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // for(int i =0 ; i < matrix.size() ;i++){
            
        //     for(int j = 0 ; j < matrix[0].size();j++){
        //         if(matrix[i][j] == target) return true;
        //     }
        // }
        // return false;

        int rowSize = matrix.size()-1;
        int colSize = matrix[0].size()-1;
        int i = 0 ;
        while(i <= rowSize ){
            if(target <= matrix[i][colSize]) {
                for(int k = 0 ; k <= colSize; k++){
                    if(matrix[i][k] == target) return true;
                }
                return false;
            }
            else{
                i++;
            }
        }
        return false;

    }
};