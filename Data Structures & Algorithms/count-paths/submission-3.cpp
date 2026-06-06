class Solution {
public:
//  stack overflow, backtracking 

    // int uniquePaths(int m, int n) {
    //     int count=0;
    //     move(0,0,m,n,count);
    //     return count;
    // }void move(int x, int y,const int &m,const int &n, int &count){
    //     if(x<0||y<0||x>=n||y>=m)return;
    //     if(x==n-1&&y==m-1){
    //         count++;
    //         return;
    //     }
    //     move(x,y+1,m,n,count);
    //     move(x+1,y,m,n,count);
    // }


// simple way 
    // int uniquePaths(int m, int n) {
    //     int total = m + n - 2;
    //     int select = min(m - 1, n - 1); 
    //     long long ans = 1;        
    //     for (int i = 1; i <= select; i++) {
    //         ans = ans * (total - select + i) / i;
    //     }
    //     return (int)ans;
    // }

//  Dp

    int uniquePaths(int m, int n){
        vector<vector<int>>grid(m,vector<int>(n,1));

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                grid[i][j]=grid[i-1][j]+grid[i][j-1];
            }
        }
        // damn nigga
        // how many paths lead to this point
        // the above most row and the leftmost column can only have 1 way 
        //  all others need to be added
        return grid[m-1][n-1];
    }
};
