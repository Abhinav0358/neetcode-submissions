class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target){
        int maxsum=0;
        int minsum=0;
        for(int i=0; i<nums.size(); i++){
            maxsum+=abs(nums[i]);
            minsum-=abs(nums[i]);
        }
        vector<vector<int>> memo(maxsum-minsum+1, vector<int>(nums.size()+1,-1));
        return move(nums,target,0,0,memo, -1*minsum);
    }
    int move(vector<int>& nums, int target, int sum, int index, vector<vector<int>> &memo, int added){
        if(index>=nums.size()){
            if(sum==target)return 1;
            return 0;
        }
        if(memo[sum+added][index]!=-1)return memo[sum+added][index]; 
        int a = move(nums,target,sum+nums[index],index+1,memo,added);
        int b = move(nums,target,sum-nums[index],index+1,memo,added);
        memo[sum+added][index]=a+b;
        return a+b;
    }
};
