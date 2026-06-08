class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        int startindex=0;
        int globalmax=nums[0];
        for(int i=0; i<2*n; i++){
            if(i>=startindex+n){
                i=++startindex;
                sum=0;
            }
            if(sum<=0)startindex=i;
            sum=max(sum+nums[i%n],nums[i%n]);
            globalmax=max(sum,globalmax);
        }
        return globalmax;
    }
};