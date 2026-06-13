class Solution {
public:
 
    vector<int> majorityElement(vector<int>& nums) {

    // using O(n) space and time

        // unordered_map<int,int> freq;
        // vector<int> ans;
        // if(nums.size()==1)return nums;
        // if(nums.size()==2&&nums[0]!=nums[1])return nums;
        // for(int a: nums){
        //     if(freq.find(a)!=freq.end()){
        //         freq[a]++;
        //         if(freq[a]>0&&freq[a]>nums.size()/3){
        //             // cout<<a<<freq[a]<<nums.size()/3<<endl;
        //             ans.push_back(a);
        //             freq[a]=-1*nums.size();
        //         }
        //     }else freq[a]=1;
        // }

        // return ans;


    // O(n) time and constant space

        int candidate1=nums[0];
        int count1=1;
        int candidate2=0;
        int count2=0;
        for(int i=1; i<nums.size(); i++){
            int num=nums[i];
            cout<<num<<" "<<candidate1<<" "<<count1<<" "<<candidate2<<" "<<count2<<endl;
            if(num==candidate1){
                count1++;
                continue;
            }
            if(num==candidate2){
                count2++;
                continue;
            }
            if(count1==0){
                candidate1=num;
                count1++;
                continue;
            }
            if(count2==0){
                candidate2=num;
                count2++;
                continue;
            }
            count1--;
            count2--;
        }
        count1=0;
        count2=0;
        for(int a: nums){
            if(a==candidate1)count1++;
            if(a==candidate2)count2++;
        }
        vector<int> ans;
        if(count1>nums.size()/3)ans.push_back(candidate1);
        if(count2>nums.size()/3)ans.push_back(candidate2);
        return ans;
    } 
};