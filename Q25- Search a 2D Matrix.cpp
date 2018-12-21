/*
Link - https://leetcode.com/problems/search-a-2d-matrix
*/

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    for(int i = 0; i < matrix.size(); i++){
        if(matrix[i].size() == 0)
            continue;
        if(matrix[i][0] <= target && matrix[i][matrix[i].size()-1] >= target){
            int j = 0, k = matrix[i].size()-1;
            while(j <= k){
                int mid = (j+k) >> 1;
                if(matrix[i][mid] == target)
                    return true;
                else if(matrix[i][mid] > target)
                    k = mid-1;
                else
                    j = mid+1;
            }
            break;
        }
    }
    return false;
}