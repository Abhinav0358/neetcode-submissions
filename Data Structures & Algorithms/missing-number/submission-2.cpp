class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int a = nums[0];
        for(int i=1; i<nums.size(); i++){
            a=a^nums[i];
        }
        for(int i=0; i<=nums.size(); i++){
            a=a^i;
        }
        return a;
    }
};
