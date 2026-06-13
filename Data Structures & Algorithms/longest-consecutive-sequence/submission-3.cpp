class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // nlogn
        // 2,3,4,4,5,10,20
        // if(nums.size()==0)return 0;
        // sort(nums.begin(), nums.end());
        // int maxcount=1;
        // int count=1;
        // for(int i=1; i<nums.size(); i++){
        //     if(nums[i]==nums[i-1])continue;
        //     if(nums[i]==nums[i-1]+1)count++;
        //     else count=1;
        //     maxcount=max(count,maxcount);
        // }
        // return maxcount;


        // O(n)
        if(nums.size()==0)return 0;
        unordered_set<int> nms;
        for(int a: nums){
            nms.insert(a);
        }
        int maxcount=1;
        for(int a : nums){
            int count=1;
            if(nms.find(a-1)!=nms.end())continue;
            while(nms.contains(a+1)){
                count++;
                a++;
            }
            maxcount=max(count,maxcount);
        }
        return maxcount;


    }
};
