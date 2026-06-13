class NumMatrix {
vector<vector<int>>sums;
public:
    //  2d prefix sum 
    NumMatrix(vector<vector<int>>& matrix) {
        sums.resize(matrix.size()+1,vector<int>(matrix[0].size()+1,0));

        for(int i=1; i<sums.size(); i++){
            for(int j=1; j<sums[0].size(); j++){
                sums[i][j]=sums[i-1][j]+sums[i][j-1]-sums[i-1][j-1]+matrix[i-1][j-1];
            }
        }

        // for(int i=0; i<sums.size(); i++){
        //     for(int j=0; j<sums[0].size(); j++){
        //         cout<<sums[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2+1][col2+1]-sums[row2+1][col1]-sums[row1][col2+1]+sums[row1][col1];   
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */