class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // how do i permute 
        // this aint about taking or not taking 
        // hm
        // what are the choices
        // hmm 
        // if i
        // take 1234
        // i can place 4 things at the start
        // and then the problem shifts to permuting the next 3 things
        // if i place 3 things at the start after that
        // the problem shifts to permuting the next 2 things
        // if i place 2 things at the start after that
        // the problem shifts to placing the last thing
        vector<vector<int>>ans;
        backtracking(ans,nums,0);
        return ans;

    }

    void backtracking(vector<vector<int>> &ans, vector<int> &nums, int index){
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
