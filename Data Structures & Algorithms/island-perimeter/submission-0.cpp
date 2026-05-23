class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid){
        bool found=false;
        int perimeter=0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1){
                    found=true;
                    move(grid,j,i,perimeter);
                    break;
                }            
            }
            if(found)break;
        }
        return perimeter;
    }
    void move(vector<vector<int>>& grid, int x, int y, int &perimeter){
        grid[y][x]=2;

        if(y<grid.size()-1&&grid[y+1][x]==1)move(grid,x,y+1,perimeter);
        if(y>=grid.size()-1||grid[y+1][x]==0)perimeter+=1;

        if(y>0&&grid[y-1][x]==1)move(grid,x,y-1,perimeter);
        if(y<=0||grid[y-1][x]==0)perimeter+=1;

        if(x<grid[0].size()-1&&grid[y][x+1]==1)move(grid,x+1,y,perimeter);
        if(x>=grid[0].size()-1||grid[y][x+1]==0)perimeter+=1;

        if(x>0&&grid[y][x-1]==1)move(grid,x-1,y, perimeter);
        if(x<=0||grid[y][x-1]==0)perimeter+=1;
    }
};