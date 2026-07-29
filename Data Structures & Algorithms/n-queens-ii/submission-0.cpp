class Solution {
public:
    int totalNQueens(int n) {
        int count=0;
        string s;
        for(int i=0; i<n; i++){
            s+='0';
        }
        vector<string> combination(n,s);
        // capture this index 
        int row=0;
        for(int i=0; i<n; i++){
            if(combination[row][i]=='.')continue;
            next(capture(combination,i,row),row+1,count);
        }

        return count;
    }
    void next(vector<string> combination, int row,int &count){
        if(row>=combination.size()){
            count++;
            return;
        }
        for(int i=0; i<combination.size(); i++){
            if(combination[row][i]=='.')continue;
            next(capture(combination,i,row),row+1,count);
        }
    }
    vector<string> capture(vector<string> combination, int x, int y) {
        int n = combination.size();

        
        for (int i = 0; i < n; i++) combination[i][x] = '.';
        for (int i = 0; i < n; i++) combination[y][i] = '.';

        
        int r, c;

        
        r = y; c = x;
        while (r >= 0 && c >= 0) combination[r--][c--] = '.';

    
        r = y; c = x;
        while (r >= 0 && c < n) combination[r--][c++] = '.';

        
        r = y; c = x;
        while (r < n && c >= 0) combination[r++][c--] = '.';

       
        r = y; c = x;
        while (r < n && c < n) combination[r++][c++] = '.';

    
        combination[y][x] = 'Q';
        return combination;
    }
};