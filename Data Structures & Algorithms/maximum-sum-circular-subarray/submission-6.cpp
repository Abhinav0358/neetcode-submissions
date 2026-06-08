class Solution {
public:
    // int maxSubarraySumCircular(vector<int>& nums) {
    //     int sum=0;
    //     int n=nums.size();
    //     int startindex=0;
    //     int globalmax=nums[0];
    //     for(int i=0; i<2*n; i++){
    //         if(i>=startindex+n){
    //             i=++startindex;
    //             sum=0;
    //         }
    //         if(sum<=0)startindex=i;
    //         sum=max(sum+nums[i%n],nums[i%n]);
    //         globalmax=max(sum,globalmax);
    //     }
    //     return globalmax;
    // }

    int maxSubarraySumCircular(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        int globalmax=nums[0];
        int minima=0;
        int total=0;
        int maxelem=nums[0];
        bool allneg=true;
        for(int i=0; i<n; i++){
            total+=nums[i];
            maxelem=max(maxelem,nums[i]);
            if(nums[i]>0)allneg=false;
        }
        if(allneg)return maxelem;
        for(int i=0; i<n; i++){
            sum=max(sum+nums[i],nums[i]);
            minima=min(minima+nums[i],nums[i]);
            globalmax=max({sum,globalmax,total-minima});
        }
        return globalmax;
    }
};