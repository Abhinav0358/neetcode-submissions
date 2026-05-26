class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int orange=0;
        queue<pair<int,int>> que;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1)orange++;
                if(grid[i][j]==2)que.push({j,i});
            }
        }
        if(orange==0)return 0;
        int minutes=-1;
        // que.push({x,y});
        while(!que.empty()){
            int size=que.size();
            minutes++;
            if(orange<=0)break;
            for(int i=0; i<size; i++){
                pair<int,int> p = que.front();
                que.pop();
                vector<int>xcomb={1,-1,0,0};
                vector<int> ycomb={0,0,1,-1};
                for(int j=0; j<4; j++){
                    int nextx=p.first+xcomb[j];
                    int nexty=p.second+ycomb[j];
                    if(nextx<0||nextx>=grid[0].size()||nexty<0||nexty>=grid.size()||grid[nexty][nextx]==0)continue;
                    if(grid[nexty][nextx]==2)continue;
                    grid[nexty][nextx]=2;
                    orange--;
                    que.push({nextx,nexty});
                }                
            }

            for(int i=0; i<grid.size(); i++){
                for(int j=0; j<grid[0].size(); j++){
                    cout<<grid[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl<<orange<<endl<<endl;

        }
        if(orange>0)return -1;
        return minutes;
    }
};
