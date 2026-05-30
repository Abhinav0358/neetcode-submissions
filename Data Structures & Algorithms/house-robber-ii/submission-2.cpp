class Solution {
public:
    int rob(vector<int>& nums) {
        int size=nums.size();
        vector<bool> robbed (size,false);
        if(size==0)return 0;
        if(size==1)return nums[0];
        if(size==2)return max(nums[0], nums[1]);
        if(size==3)return max(max(nums[0],nums[1]),nums[2]);

        int third=0;
        int first=nums[2]+third;
        int second=nums[1];


        // skip the first element 
        for(int i=3; i<size; i++){
            int next=max(nums[i]+second,nums[i]+third);
            third=second;
            second=first;
            first=next;
            cout<<next<<" ";
         }
         int skipfirst=max(first,second);
        
        //  include first
         first=nums[2]+nums[0];
         second=0;
         third=nums[0];
         for(int i=3; i<size-1; i++){
            int next2=max(nums[i]+second,nums[i]+third);
            third=second;
            second=first;
            first=next2;
         }
         int includefirst=max(first,second);


         return max(includefirst,skipfirst);
    }
};
