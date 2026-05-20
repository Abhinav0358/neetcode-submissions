class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int>subset;
        backtracking(nums,target,0,ans,subset,0);
        return ans;
    }
    void backtracking(vector<int>& nums, int target, int index, vector<vector<int>> &ans, vector<int> subset, int currsum){
        if(currsum==target)ans.push_back(subset);
        if(currsum>=target)return;
        if(index>=nums.size())return;
        subset.push_back(nums[index]);
        backtracking(nums,target,index,ans,subset, currsum+nums[index]);
        subset.pop_back();
        backtracking(nums,target,index+1,ans,subset, currsum);
    }
};
