class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s="";
        int count=0;
        backtracking(s,n,ans,count);
        return ans;
    }
    void backtracking(string s, int n, vector<string> &ans, int count){
        if(s.size()==2*n&&count==0){
            ans.push_back(s);
            return;
        }
        if(s.size()>=2*n&&count!=0)return;
        cout<<s<<endl;
        backtracking(s+"(",n,ans,count+1);
        if(count>0){
        backtracking(s+")",n,ans,count-1);
        }
        cout<<s<<endl;
    }
};
