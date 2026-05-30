class Solution {
public:
    int rob(vector<int>& nums) {
        int size=nums.size();
        if(size==0)return 0;
        if(size==1)return nums[0];
        if(size==2)return max(nums[0], nums[1]);
        if(size==3)return max(nums[0]+nums[2], nums[1]);

        int first=nums[2]+nums[0];
        int second=nums[1];
        int third=nums[0];

        for(int i=3; i<size; i++){
            int next=max(nums[i]+second,nums[i]+third);
            third=second;
            second=first;
            first=next;
         }

         return max(first,second);


        
    }
};
