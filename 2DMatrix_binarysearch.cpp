class Solution {
public:
    //binary search it
    /*
    Index conversion:

    Convert from 2D to 1D
    row: 1, col: 2 ---> 1D index: row*len(row) + col = 6

    Convert from 1D to 2D
    ix = 6 -> row = mid / len(row), col = mid % len(row)
    */

    bool binarySearch(vector<vector<int>>& matrix, int l, int r, int x){
        int lenRow = matrix[0].size();
        if(r >= l){
            int mid = l + (r - l) / 2;
            //cout << mid << endl;


            int col = mid % lenRow;
            int row = mid / lenRow;

            if(matrix[row][col] == x){
                return true;
            }

            if(matrix[row][col] > x){
                return binarySearch(matrix, l, mid - 1, x);
            } else {
                return binarySearch(matrix, mid + 1, r, x);
            }


        }

        return false;

    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0){
            return false;
        }
        return binarySearch(matrix, 0, matrix[0].size() * matrix.size() - 1, target);
    }
};
