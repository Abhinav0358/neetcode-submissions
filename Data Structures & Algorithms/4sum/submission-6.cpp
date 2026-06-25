class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++)cout<<nums[i]<<"  ";
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        cout<<endl;
        for(int i=0; i<nums.size(); i++)cout<<nums[i]<<"  ";

        for(int i=0; i<nums.size(); i++){
            if(i>0&&nums[i]==nums[i-1])continue;
            // if(lookingfor<0)continue;
            for(int j=i+1; j<nums.size(); j++){
                if(nums[j]==nums[j-1]&&j!=i+1)continue;
                // if(lookingfor<0)continue;
                int left=j+1;
                int right=nums.size()-1;
                while(left<right){
                    if((long long)nums[i]+nums[j]+nums[left]+nums[right]==(long long)target){
                        answer.push_back({nums[i],nums[j],nums[left], nums[right]});
                        left++;
                        right--;
                        while(nums[left]==nums[left-1]&&nums[right]==nums[right+1]){
                            left++;
                            right--;
                            if(left>=right)break;
                        }
                    }
                    if(left>=right)break;
                    else if((long long)nums[i]+nums[j]+nums[left]+nums[right]>(long long)target)right--;
                    else if((long long)nums[i]+nums[j]+nums[left]+nums[right]<(long long)target)left++;
                }
            }
        }

        return answer;
    }
};