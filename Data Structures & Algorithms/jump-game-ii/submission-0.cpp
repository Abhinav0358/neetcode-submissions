class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> minjumps(nums.size(),nums.size());
        minjumps[0]=0;
        for(int i=1; i<nums.size(); i++){
            for(int j=i-1; j>=0; j--){
                if(nums[j]>=i-j)minjumps[i]=min(minjumps[j]+1,minjumps[i]);
            }
        }
        return minjumps[minjumps.size()-1];
    }
};
