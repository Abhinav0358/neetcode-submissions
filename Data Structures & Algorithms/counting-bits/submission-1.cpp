class Solution {
public:
    vector<int> countBits(int n){
        
        vector<int> ans(n+1);
        ans[0]=0;
        if(n==0)return ans;
        ans[1]=1;
        if(n==1)return ans;
        for(int i=2; i<=n; i++){
            // cout<<ans[i]<<" "<<ans[i/2]<<" "<<(i&1)<<endl;
            ans[i]=ans[i/2]+(i&1);
        }

        return ans;

    }
};
