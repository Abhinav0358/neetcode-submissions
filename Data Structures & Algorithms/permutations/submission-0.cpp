class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // how do i permute 
        // this aint about taking or not taking 
        // hm
        // what are the choices 
        // keep a number at a place
        // somehow remember?
        // that 3,4 has been placed at the starting at 1,2 are left?
        // or swap - swap
        vector<vector<int>>ans;
        backtracking(ans,nums,0);
        return ans;

    }

    void backtracking(vector<vector<int>> &ans, vector<int> nums, int index){
        if(index>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=index; i<nums.size(); i++){
            swap(nums[index],nums[i]);
            backtracking(ans,nums,index+1);
            swap(nums[index],nums[i]);
        }
    }
};
