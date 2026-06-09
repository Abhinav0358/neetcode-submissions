class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        // for square matrices

        // int n=matrix.size();
        // for(int i=0; i<n; i++){
        //     for(int j=i+1; j<n; j++){
        //         swap(matrix[i][j],matrix[j][i]);
        //     }
        // }
        // return matrix;


        // should i create a copy?

        vector<vector<int>>transpose(matrix[0].size(),vector<int>(matrix.size()));

        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                transpose[j][i]=matrix[i][j];
            }
        }
        return transpose;
        
    }
};