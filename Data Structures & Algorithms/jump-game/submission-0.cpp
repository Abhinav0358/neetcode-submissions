class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool canreachi=false;

        for(int i=1; i<nums.size(); i++){
            canreachi=false;
            for(int j=1; j<=i; j++){
                if(j<=nums[i-j]){
                    canreachi=true;
                    break;
                }
            }
            if(!canreachi)return false;
        }
        return true;
    }
};
