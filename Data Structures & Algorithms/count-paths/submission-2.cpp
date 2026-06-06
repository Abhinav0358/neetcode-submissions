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
    int uniquePaths(int m, int n) {
        int N = m + n - 2;
        int K = min(m - 1, n - 1); 
        
        long long ans = 1;
        
        for (int i = 1; i <= K; i++) {
            ans = ans * (N - K + i) / i;
        }
        
        return (int)ans;
    }
};
