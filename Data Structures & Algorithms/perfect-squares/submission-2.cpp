class Solution {
public:
    int numSquares(int n) {
        // bottom up approach 
        vector<int> dp(n+1,n);
        dp[0]=0;
        for(int i=1; i<=n; i++){
            for(int j=0; j*j<=i; j++){
                dp[i]=min(dp[i],dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};


// backtracked solution

// class Solution {
// public:
//     int numSquares(int n) {
//         // what is the no that u need to write upto
//         // lets say well upto the number whose square is not greater that that no 
//         // so 
//         // memoize this
//         int cap;
//         for(int i=1; i<=n; i++){
//             if(i*i==n){
//                 cap=i;
//                 return 1;
//             }
//             if(i*i>n){
//                 cap=i;
//                 break;
//             }
//         }

//         cap--;
//         int mincount=100;
//         takenottake(n,1,0,mincount,0,cap);
//         return mincount;
//     }
//     void takenottake(int n, int index, int currsum,int &mincount, int count,int cap){
//         if(currsum>n||count>mincount||index>cap)return;
//         if(currsum==n){
//             mincount=min(count,mincount);
//             return;
//         }
//         takenottake(n,index,currsum+index*index,mincount,count+1,cap);
//         takenottake(n,index+1,currsum,mincount,count,cap);
//     }
// };