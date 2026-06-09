class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0; i<n/2; i++){
            for(int j=i; j<n-i-1; j++){
                circle(matrix,n-2*i,i,j);
            }
        }
    }
    void circle(vector<vector<int>>& matrix,int side, int i, int j){
        // matrix[i][j];
        int a = matrix[j][i+side-1];
        matrix[j][i+side-1]=matrix[i][j];
        int b = matrix[i+side-1][2*i+side-j-1];
        matrix[i+side-1][2*i+side-j-1]=a;
        int c = matrix[2*i+side-j-1][i];
        matrix[2*i+side-j-1][i]=b;
        matrix[i][j]=c;

        for(int k=0; k<matrix.size(); k++){
            for(int m=0; m<matrix.size(); m++){
                cout<<matrix[k][m]<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
        
    }

};
