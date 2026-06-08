class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // knapsack
        int sum=0;
        int globalmax=nums[0];
        for(int i=0; i<nums.size(); i++){
        sum=max(sum+nums[i],nums[i]);
        globalmax=max(sum,globalmax);
        }
        return globalmax;
    }
};
