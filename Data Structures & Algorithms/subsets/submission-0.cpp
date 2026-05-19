class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int> currvec;
        int currindex=0;
        backtrack(nums, currvec, currindex, ans);
        return ans;

    }
    void backtrack(vector<int>& nums, vector<int> currentvec, int currentindex, vector<vector<int>>&ans){
        if(currentindex==nums.size()){
            ans.push_back(currentvec);
            return;
        }

        currentvec.push_back(nums[currentindex]);
        backtrack(nums,currentvec, currentindex+1,ans);
        currentvec.pop_back();
        backtrack(nums,currentvec, currentindex+1, ans);
    }
};
