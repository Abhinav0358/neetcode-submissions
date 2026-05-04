class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zcount=0;
        int ocount=0;
        int tcount=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0)zcount++;
            else if(nums[i]==1)ocount++;
            else if(nums[i]==2)tcount++;
        }
        for(int i=1; i<=nums.size(); i++){
            if(i<=zcount)nums[i-1]=0;
            else if(i<=(zcount+ocount))nums[i-1]=1;
            else if(i<=(zcount+tcount+ocount))nums[i-1]=2;
        }
        
    }
};