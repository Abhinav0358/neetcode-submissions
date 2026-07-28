class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>>seenvalues (matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                longest(matrix, seenvalues,j,i);
            }
        }

        int ans=0;

        for(int i=0; i<seenvalues.size(); i++){
            for(int j=0; j<seenvalues[0].size(); j++){
                ans=max(ans,seenvalues[i][j]);
            }
        }

        return ans;

    }
    int longest(vector<vector<int>>& matrix,vector<vector<int>>& seenvalues, int x, int y){
        if(seenvalues[y][x]!=0)return seenvalues[y][x];
        if(x-1>=0&&matrix[y][x-1]>matrix[y][x]){
            seenvalues[y][x]=longest(matrix,seenvalues,x-1,y)+1;
        }
        if(y-1>=0&&matrix[y-1][x]>matrix[y][x]){
            seenvalues[y][x]=max(longest(matrix,seenvalues,x,y-1)+1,seenvalues[y][x]);
        }
        if(y+1<matrix.size()&&matrix[y+1][x]>matrix[y][x]){
            seenvalues[y][x]=max(longest(matrix,seenvalues,x,y+1)+1,seenvalues[y][x]);
        }
        if(x+1<matrix[0].size()&&matrix[y][x+1]>matrix[y][x]){
            seenvalues[y][x]=max(longest(matrix,seenvalues,x+1,y)+1,seenvalues[y][x]);
        }
        if(seenvalues[y][x]==0)seenvalues[y][x]=1;
        return seenvalues[y][x];
    }
};
