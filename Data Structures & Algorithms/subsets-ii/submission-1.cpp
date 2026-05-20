class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // first ig lets sort
        // then avoid repetitions
        // repetition - include first 1 then exclude next 1 , exclude first 1 then include next 1
        vector<vector<int>> ans;
        vector<int> currvec;
        sort(nums.begin(),nums.end());
        backtracking(ans, nums,0, currvec);
        return ans;

    }void backtracking(vector<vector<int>> &ans, vector<int> &nums, int index, vector<int> currvec){
        for(int i=index; i<=nums.size(); i++){
            if(i>=nums.size()){
                ans.push_back(currvec);
                return;
            }
            if(i>index&&nums[i]==nums[i-1])continue; // duplicatess avoiding 
            currvec.push_back(nums[i]);
            backtracking(ans,nums,i+1, currvec);
            currvec.pop_back();
        }
    }
};
