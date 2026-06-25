class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            cout<<nums[i]<<" ";
        }
        for(int i=0; i<nums.size(); i++){
            puttocorrectplace(nums,nums[i]);
        }
        cout<<endl;
        for(int i=0; i<nums.size(); i++){
            cout<<nums[i]<<" ";
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=i+1)return i+1;
        }
        return nums.size()+1;
    }
    void puttocorrectplace(vector<int>& nums, int i){
        if(i<1||i>nums.size())return;
        if(nums[i-1]==i)return;
        int tmp=nums[i-1];
        nums[i-1]=i;
        puttocorrectplace(nums,tmp);
    }
};  