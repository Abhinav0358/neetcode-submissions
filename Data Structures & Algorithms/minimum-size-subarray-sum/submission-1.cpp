class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left =0;
        int sum=0;
        int minlength=999;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            while(sum>=target){
                if(i-left+1<minlength)minlength=i-left+1; 
                sum-=nums[left];
                left++;            }
        }
        if(minlength==999)return 0;

        return minlength;
    }
};