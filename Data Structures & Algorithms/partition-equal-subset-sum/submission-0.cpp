class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
        }
        bool ans=false;
        takeornot(nums,0,0,ans,sum);
        return ans;
    }
    void takeornot(vector<int>& nums,int index,int currsum,bool &ans,int sum){
        if(ans)return;
        if(2*currsum==sum){
            ans=true;
            return;
        }
        if(2*currsum>sum||index>=nums.size()){
            return;
        }
        takeornot(nums,index+1,currsum+nums[index],ans,sum);
        takeornot(nums,index+1,currsum,ans,sum);
    }
};
