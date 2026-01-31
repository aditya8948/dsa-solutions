class Solution {
public:
    // Counts how many elements in the matrix are <=  element
    int countElement(vector<vector<int>>& matrix, int element, int n) {
        int row = n - 1;   // start from bottom-left row
        int col = 0;       // start from first column
        int elementCount = 0;

       // matrix sorted order mai hai to ek element ko check kr pure row ko discard kar skate hai
        while (row >= 0 && col < n) {
            // agar current element is <= element,
            // then all elements above it in this column are also <= element
            if (matrix[row][col] <= element) {
                elementCount += row + 1;
                col++;                   // move to next column
            }
            // current element is greater than element,
            // to uper smaller values
            else {
                row--;
            }
        }
        return elementCount;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int min = matrix[0][0]; // minimum value 
        int max = matrix[n - 1][n - 1]; // max value 

        while (min < max) {
            int mid = min + (max - min) / 2;

            int count = countElement(matrix, mid, n);

            // agar count km hai to wo number kth positionn se phle hai
            // the k-th smallest must be larger
            if (count < k) {
                min = mid + 1;
            }
            // nhi to  mid could be the answer
            else {
                max = mid;
            }
        }
        return min;
    }
};
