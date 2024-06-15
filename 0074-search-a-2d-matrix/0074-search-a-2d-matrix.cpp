class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0) return false;
        int m = matrix[0].size();
        if (m == 0) return false;

        int left = 0, right = n * m - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int mid_value = matrix[mid / m][mid % m];
            if (mid_value == target) {
                return true;
            } else if (mid_value < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};



// class Solution {
// public:
    
//     void swaprows(vector<vector<int>>& matrix,int x){
        
//         int n = matrix.size();
//         int m = matrix[0].size();
        
//         for(int i = 0 ; i<m ; i++){
//             swap(matrix[x][i],matrix[x+1][i]);
//         }
//     }
    
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
//         int n = matrix.size();
//         int m = matrix[0].size();
        
//         for(auto i : matrix ){
//             sort(i.begin(),i.end());
//         }
        
//         for(int i = 0 ; i< m-1 ; i++){
//             if(matrix[i][0] > matrix[i+1][0]){
//                 //swaprowfunction
//             }
//         }
        

        
//     }
// };