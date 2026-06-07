class Solution {
public:
    int longestCommonSubsequence(string text1, string text2){
        // Backtracking
        // return lcs(text1,text2,text1.size(),text2.size());

        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0)); 

        for(int i=1; i<dp.size(); i++){
            for(int j=1; j<dp[0].size(); j++){
                if(text1[i-1]==text2[j-1])dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }   
        }
        return dp[dp.size()-1][dp[0].size()-1];
    }
    // int lcs(string &text1, string &text2, int i, int j){
    //     if(i==0 || j==0)return 0;

    //     if(text1[i-1]==text2[j-1])return 1+lcs(text1,text2,i-1,j-1);

    //     return max(lcs(text1,text2,i-1,j),lcs(text1,text2,i,j-1));
    // }
};
