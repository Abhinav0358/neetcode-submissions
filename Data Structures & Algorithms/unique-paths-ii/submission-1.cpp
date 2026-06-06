class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //    so dp huh 
        // maybe initialization has to be different 
        // now you get to a block still there are same ways of getting to it
        //  but if the block itself is 1, make it 0? so that the block below takes 0 from this
        //  ye 

        vector<vector<int>> grid(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),1));

        // initialzation
        bool pathblocked=false;
        for(int i=0; i<obstacleGrid[0].size(); i++){
            if(obstacleGrid[0][i]==1)pathblocked=true;
            pathblocked? grid[0][i]=0 : grid[0][i]=1;
        }
        pathblocked=false;
        for(int i=0; i<obstacleGrid.size(); i++){
            if(obstacleGrid[i][0]==1)pathblocked=true;
            pathblocked? grid[i][0]=0 : grid[i][0]=1;
        }

        // loop
        for(int i=1; i<obstacleGrid.size(); i++){
            for(int j=1; j<obstacleGrid[0].size(); j++){
                obstacleGrid[i][j]==1? grid[i][j]=0 : grid[i][j]=grid[i-1][j]+grid[i][j-1];
            }
        }
        return grid[grid.size()-1][grid[0].size()-1];
    }
};


// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         // you wanna backtrack in 2 mins? ye
//         // ok so backtracking got fucked 
//         int count=0;
//         moove(0,0,obstacleGrid,count);
//         return count;
//     }void moove(int x, int y, vector<vector<int>>& obstacleGrid, int &count){
//         if(x<0||y<0||x>=obstacleGrid[0].size()||y>=obstacleGrid.size())return;
//         if(x==obstacleGrid[0].size()-1&&y==obstacleGrid.size()-1){
//             count++;
//             return;
//         }
//         if(obstacleGrid[y][x]==1)return;
//         moove(x+1,y,obstacleGrid,count);
//         moove(x,y+1,obstacleGrid,count);
//     }
// };