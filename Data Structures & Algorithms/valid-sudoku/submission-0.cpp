class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
     unordered_set<char> hset;
     for(vector<char> row : board){
        for(char box: row){
            if(hset.contains(box))return false;
            if(box=='.')continue;
            hset.insert(box);
        }
        hset.clear();
     }
     for(int i=0; i<board.size(); i++){
         for(int j=0; j<board.size(); j++){
            if(hset.contains(board[j][i]))return false;
            if((board[j][i])=='.')continue;
            hset.insert(board[j][i]);
         }
         hset.clear();
     }

     for(int i=0; i<board.size(); i+=3){
        for(int j=0; j<board.size(); j+=3){
            for(int k=i; k<i+3; k++){
                for(int l=j; l<j+3; l++){
                    if((board[k][l])=='.')continue;
                    if(hset.contains(board[k][l]))return false;
                    hset.insert(board[k][l]);
                }
            }
            hset.clear();  
         }  
     }
        return true;
    }
};
