class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int> currvec;
        backtrack(n,k,ans,currvec,1);
        return ans;
    }
    void backtrack(int n, int k, vector<vector<int>> &ans, vector<int> currvec,int index){
        // std binary approach
        if(currvec.size()>=k){
            ans.push_back(currvec);
            return;
        }
        if(index>n)return;
        currvec.push_back(index);
        backtrack(n,k,ans,currvec,index+1);
        currvec.pop_back();
        backtrack(n,k,ans,currvec,index+1); 
    }
};