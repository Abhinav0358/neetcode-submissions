class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // nlogn
        // 2,3,4,4,5,10,20
        if(nums.size()==0)return 0;
        sort(nums.begin(), nums.end());
        int maxcount=1;
        int count=1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==nums[i-1])continue;
            if(nums[i]==nums[i-1]+1)count++;
            else count=1;
            maxcount=max(count,maxcount);
        }

        return maxcount;

    }
};
