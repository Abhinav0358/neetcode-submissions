class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;
        vector<int> ans;
        if(nums.size()==1)return nums;
        if(nums.size()==2&&nums[0]!=nums[1])return nums;
        for(int a: nums){
            if(freq.find(a)!=freq.end()){
                freq[a]++;
                if(freq[a]>0&&freq[a]>nums.size()/3){
                    // cout<<a<<freq[a]<<nums.size()/3<<endl;
                    ans.push_back(a);
                    freq[a]=-1*nums.size();
                }
            }else freq[a]=1;
        }

        return ans;
    }
};