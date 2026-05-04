class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());  // nlog(n);
        vector<vector<int>>answer;

        for(int i=0; i<nums.size()-2; i++){
            int target = nums[i]*-1;
            int left = i+1;
            int right = nums.size()-1;
            if(nums[i]==nums[i-1]&&i>=1)continue;
            cout<<target<<" "<<nums[left]<<" "<<nums[right]<<endl;
            while(right>left){
                if(nums[right]+nums[left]==target){
                answer.push_back({nums[i],nums[left],nums[right]});
                left++;
                right--;
                while(left<right&&nums[left-1]==nums[left])left++;
                while(left<right&&nums[right+1]==nums[right])right--;
                }
                else if(nums[right]+nums[left]<target)left++;
                else if(nums[right]+nums[left]>target)right--;
            }
        }
        return answer;
    }
};
