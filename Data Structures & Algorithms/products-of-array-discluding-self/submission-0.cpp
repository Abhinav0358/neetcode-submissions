class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod=1;
        int zerocount=0;
        int zindex;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                if(zerocount==0){
                    zerocount++;
                    zindex=i;
                    continue;
                }
                else{
                    vector<int> result(nums.size(),0);
                    return result;
                }
            }
            prod*=nums[i];
        }
        vector<int> result(nums.size());
        if(zerocount==1){
            vector<int> result(nums.size(),0);
            result[zindex]=prod;
            return result;
        }
        for(int i=0; i<nums.size(); i++){
            result[i]=prod/nums[i];
        }
        return result;

    }
};
