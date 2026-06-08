class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int ans=0;
        vector<vector<int>> exists(amount+1, vector<int>(coins.size()+1,-1));
        
        return move(amount,coins,0,0,ans,exists); 
    }
    int move(const int amount, vector<int>& coins, int sum, int index, int ans, vector<vector<int>> &exists){
        if(sum>amount)return ans;
        if(index>=coins.size())return ans;
        // for(int i=0; i<exists.size(); i++){
        //     for(int j=0; j<exists[0].size(); j++){
        //         cout<<exists[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl<<endl;
        if(exists[sum][index]!=-1){
            return exists[sum][index];
        }
        if(sum==amount){
            ans++;
            exists[sum][index]=ans;
            return ans;
        }
        int a = move(amount, coins, sum + coins[index], index,ans,exists);
        int b = move(amount, coins, sum, index+1,ans,exists);
        exists[sum][index]=a+b;
        return a+b;
    }
};
