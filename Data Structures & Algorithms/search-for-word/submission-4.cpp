class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool ans=false;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]==word[0])backtrack(board, word,i,j,ans,1);
                if(ans)break;
            }
            if(ans)break;
        }
        return ans;
    }
    void backtrack(vector<vector<char>>& board, string word, int y, int x, bool &ans, int index){
        if(index>=word.size()){
            ans=true;
            return;
        }
        char original_char=board[y][x];
        board[y][x]='#';
        if(y>0&&(board[y-1][x]==word[index])){
            backtrack(board, word, y-1, x, ans, index+1);
            // board[y][x]=original_char;
        }
        if(y<board.size()-1&&(board[y+1][x]==word[index])){
            backtrack(board, word, y+1, x, ans, index+1);
            // board[y][x]=original_char;
        }
        if(x>0&&(board[y][x-1]==word[index])){
            backtrack(board, word, y, x-1, ans, index+1);
            // board[y][x]=original_char;
        }
        if(x<board[0].size()-1&&(board[y][x+1]==word[index])){
            backtrack(board, word, y, x+1, ans, index+1);
            // board[y][x]=original_char;
        }
            board[y][x]=original_char;
    }
};
