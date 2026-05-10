class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int n = matrix[0].size();
        int m = matrix.size();
        int right = m*n-1;

        if(matrix[0][0]==target)return true;
        if(matrix[m-1][n-1]==target)return true;

        while(left<right){
            int mid = (left + right)/2;
            int midval = matrix[mid/n][mid%n];
            if(midval==target)return true;
            else if(midval<target){
                left = mid;
            }else right = mid;

            if(right-left==1)return false;
        }

        return false;

    }
};
