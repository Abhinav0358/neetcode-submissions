class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]=='1'){
                    markisland(grid,j,i);
                    count++;
                }
            }   
        }
        return count;
    }
    void markisland(vector<vector<char>> &grid, int x, int y){
        grid[y][x]='2';
        if(y<grid.size()-1&&grid[y+1][x]=='1')markisland(grid,x,y+1);
        if(y>0&&grid[y-1][x]=='1')markisland(grid,x,y-1);
        if(x<grid[0].size()-1&&grid[y][x+1]=='1')markisland(grid,x+1,y);
        if(x>0&&grid[y][x-1]=='1')markisland(grid,x-1,y);
    }
};
