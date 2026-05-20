class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> currvec;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, 0, target, currvec,0, ans);
        return ans;
    }
    // fuck it, this is choices backtracking

    // void backtracking(vector<int> &candidates, int index, int target, vector<int> currvec, int currsum, vector<vector<int>> &ans){
    //     if(currsum==target) ans.push_back(currvec);
    //     if(currsum>=target)return;
    //     if(index>=candidates.size())return;
    //     currvec.push_back(candidates[index]);
    //     backtracking(candidates,index+1,target,currvec, currsum+candidates[index],ans);
    //     // if(candidates[index]==candidates[index-1]){
    //     //     return;
    //     // }
    //     currvec.pop_back();
    //     backtracking(candidates,index+1,target,currvec, currsum, ans);
    // }


    // if we do iterative backtracking 

    void backtracking(vector<int> &candidates, int index, int target, vector<int> currvec, int currsum, vector<vector<int>> &ans){
        if(currsum==target)ans.push_back(currvec);
        if(currsum>=target)return;
        for(int i=index; i<candidates.size(); i++){
            if(i>index&&candidates[i]==candidates[i-1])continue;
            currvec.push_back(candidates[i]);
            backtracking(candidates,i+1,target, currvec,currsum+candidates[i],ans);
            currvec.pop_back();
        }
    }

};
