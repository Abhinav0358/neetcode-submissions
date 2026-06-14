class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> spiral;
        doaloop(matrix,spiral,matrix[0].size(),matrix.size(),0,0);
        return spiral;
    }
    void doaloop(vector<vector<int>>& matrix, vector<int> &spiral, int sidex, int sidey, int startx, int starty){
        // spiral.push_back(matrix[starty][startx]);
        // if(startx>=matrix[0].size()/2||starty>=matrix.size()/2){
        //     if(matrix[0].size()%2!=0||matrix.size()%2!=0)spiral.push_back(matrix[starty][startx]);
        //     return;
        // }

       if (sidex == 1) {
            for (int i = starty; i < starty + sidey; i++) {
                spiral.push_back(matrix[i][startx]);
            }
            return;
        }
        
        if (sidey == 1) {
            for (int i = startx; i < startx + sidex; i++) {
                spiral.push_back(matrix[starty][i]);
            }
            return;
        }

        if(sidex<=0||sidey<=0)return;
        for(int i=startx; i<startx+sidex-1; i++){
            spiral.push_back(matrix[starty][i]);
        }
        for(int i=starty; i<starty+sidey-1; i++){
            spiral.push_back(matrix[i][startx+sidex-1]);
        }
        for(int i=startx+sidex-1; i>startx; i--){
            spiral.push_back(matrix[starty+sidey-1][i]);
        }
        for(int i=starty+sidey-1; i>starty; i--){
            spiral.push_back(matrix[i][startx]);
        }
        doaloop(matrix,spiral,sidex-2,sidey-2,startx+1,starty+1);
    }
};
