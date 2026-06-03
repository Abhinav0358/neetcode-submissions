class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int maxprod=nums[0];
        for(int i=0; i<nums.size(); i++){
            int product=1;
            for(int j=i; j<nums.size(); j++){
                product*=nums[j];
                maxprod=max(product,maxprod);
            }
        }
        return maxprod;
    }
};
