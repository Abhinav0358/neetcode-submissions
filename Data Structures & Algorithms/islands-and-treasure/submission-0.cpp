class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==0)markdistance(grid,j,i,0);
            }
        }        
    }
    void markdistance(vector<vector<int>>& grid, int x, int y, int distance){
        
        if(y<0||y>=grid.size()||x<0||x>=grid[0].size()||grid[y][x]==-1){
            return;
        }
        if(grid[y][x]==0&&distance!=0){
            return;
        }
        if(grid[y][x]<distance)return;
        grid[y][x]=distance;

        // for(int i=0; i<grid.size(); i++){
        //     for(int j=0; j<grid[0].size(); j++){
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        // cout<<endl;     
        
        markdistance(grid,x+1,y,distance+1);
        markdistance(grid,x-1,y,distance+1);
        markdistance(grid,x,y+1,distance+1);
        markdistance(grid,x,y-1,distance+1);
    }
};
