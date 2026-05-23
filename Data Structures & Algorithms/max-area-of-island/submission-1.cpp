class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea=0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1){
                    int area=0;
                    areaofisland(grid,j,i,area);  // mark + give area
                    maxarea=max(area,maxarea);
                }
            }
        }
        return maxarea;
    }
    void areaofisland(vector<vector<int>>& grid, int x, int y, int &area){
        if(y<0||y>=grid.size()||x<0||x>=grid[0].size()||grid[y][x]!=1)return;
        grid[y][x]=2;
        area+=1;
        areaofisland(grid,x,y+1,area);
        areaofisland(grid,x,y-1,area);
        areaofisland(grid,x+1,y,area);
        areaofisland(grid,x-1,y,area);
    }
};
