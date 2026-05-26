class Solution {
public:
    void solve(vector<vector<char>>& board) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]=='O'){
                    if(i==0||i==board.size()-1|j==0||j==board[0].size()-1)convert(board,j,i);
                }
            }
        }
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]=='O')board[i][j]='X';
            }
        }
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]=='#')board[i][j]='O';
            }
        }
    }
    void convert(vector<vector<char>>& board, int x, int y){
        if(x<0||x>=board[0].size()||y<0|y>=board.size())return;
        if(board[y][x]=='O'){
            board[y][x]='#';
            convert(board,x+1,y);
            convert(board,x,y+1);
            convert(board,x-1,y);
            convert(board,x,y-1);
        }
    }
};
