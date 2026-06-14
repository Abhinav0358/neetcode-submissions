class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights){
        vector<vector<int>> ans;
        vector<vector<int>> tru (heights.size(), vector<int>(heights[0].size(),0));
        for(int i=0; i<heights[0].size(); i++){
            connectedtopacific(heights,i,0,heights[0][i],tru);
        }
        for(int i=0; i<heights.size(); i++){
            connectedtopacific(heights,0,i,heights[i][0],tru);
        }
        for(int i=0; i<heights[0].size(); i++){
            connectedtoatlantic(heights,i,heights.size()-1,heights[heights.size()-1][i],ans,tru);
        }
        for(int i=0; i<heights.size(); i++){
            connectedtoatlantic(heights,heights[0].size()-1,i,heights[i][heights[0].size()-1],ans,tru);
        }
        return ans;
    }
    void connectedtopacific(vector<vector<int>>& heights, int x, int y, int parentvalue,vector<vector<int>> &tru){
        if(x<0||y<0||x>=heights[0].size()||y>=heights.size())return;
        if(heights[y][x]<parentvalue)return;
        if(tru[y][x]==1)return;
        tru[y][x]=1;
        connectedtopacific(heights,x-1,y,heights[y][x],tru);
        connectedtopacific(heights,x+1,y,heights[y][x],tru);
        connectedtopacific(heights,x,y-1,heights[y][x],tru);
        connectedtopacific(heights,x,y+1,heights[y][x],tru); 
    }
    void connectedtoatlantic(vector<vector<int>>& heights, int x, int y, int parentvalue,vector<vector<int>> &ans,vector<vector<int>> &tru){
        if(x<0||y<0||x>=heights[0].size()||y>=heights.size())return;
        if(heights[y][x]<parentvalue)return;
        if(tru[y][x]==2)return;
        if(tru[y][x]==1){
            ans.push_back({y,x});
        }
        tru[y][x]=2;
        connectedtoatlantic(heights,x-1,y,heights[y][x],ans,tru);
        connectedtoatlantic(heights,x+1,y,heights[y][x],ans,tru);
        connectedtoatlantic(heights,x,y-1,heights[y][x],ans,tru);
        connectedtoatlantic(heights,x,y+1,heights[y][x],ans,tru); 
    }
};
