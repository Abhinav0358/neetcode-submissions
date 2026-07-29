class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s;
        for(int i=0; i<n; i++){
            s+='0';
        }
        vector<string> combination(n,s);
        // capture this index 
        int row=0;
        for(int i=0; i<n; i++){
            if(combination[row][i]=='.')continue;
            next(capture(combination,i,row),row+1,ans);
        }

        return ans;
    }
    void next(vector<string> combination, int row,vector<vector<string>> &ans){
        if(row>=combination.size()){
            ans.push_back(combination);
            return;
        }
        for(int i=0; i<combination.size(); i++){
            if(combination[row][i]=='.')continue;
            next(capture(combination,i,row),row+1,ans);
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
