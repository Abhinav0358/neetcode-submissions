class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix){
        bool islastrowzero=false;

        for(int j=0; j<matrix[0].size(); j++){
            if(matrix[matrix.size()-1][j]==0){
                islastrowzero=true;
                break;
            }
        }


        for(int i=0; i<matrix.size()-1; i++){
            bool setrowzerobool=false;
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]==0){
                    setrowzerobool=true;
                    matrix[matrix.size()-1][j]=0;
                }
            }
            if(setrowzerobool)setrowzero(matrix,i);
        }
        
        for(int j=0; j<matrix[0].size(); j++){
            if(matrix[matrix.size()-1][j]==0)setcolumnzero(matrix,j);
        }

        if(islastrowzero)setrowzero(matrix,matrix.size()-1);
        
    }
    void setrowzero(vector<vector<int>>& matrix,int r){
        for(int i=0; i<matrix[0].size(); i++){
            matrix[r][i]=0;
        }
    }

    void setcolumnzero(vector<vector<int>>& matrix,int c){
        for(int i=0; i<matrix.size(); i++){
            matrix[i][c]=0;
        }
    }


};
