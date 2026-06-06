class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>sum(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(i==0&&j==0){
                    sum[i][j]=grid[i][j];
                    continue;
                }
                if(i==0){
                    sum[i][j]=grid[i][j]+sum[i][j-1];
                    continue;
                }
                if(j==0){
                    sum[i][j]=grid[i][j]+sum[i-1][j];
                    continue;
                }
                sum[i][j]=min(sum[i-1][j],sum[i][j-1])+grid[i][j];
            }
        }

        return sum[sum.size()-1][sum[0].size()-1];   
    }
};