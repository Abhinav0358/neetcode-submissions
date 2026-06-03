class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lisati(nums.size(),1);
        int globalmax=1;
        for(int i=1; i<nums.size(); i++){
            for(int j=i; j>=0; j--){
                if(nums[j]<nums[i]){
                    lisati[i]=max(lisati[i],lisati[j]+1);
                    globalmax=max(globalmax,lisati[i]);
                }
            }
        }
        return globalmax;
    }
};
