// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int ans=-1;
//         for(int i=0; i<nums.size(); i++){
//             placeatrightindex(nums,i,ans);
//             if(ans!=-1)return ans;
//         }
//         for(int i=0; i<nums.size(); i++){
//             if(nums[i]!=i+1)return nums[i];
//         }
//         return 1;
//     }
//     void placeatrightindex(vector<int>& nums, int index, int &ans){
//         int a = nums[index];
//         int tmp = nums[a-1];
//         if(a==index+1)return;
//         if(nums[a-1]==a){
//             ans=a;
//             return;
//         }
//         nums[a-1]=a;
//         placeatrightindex(nums,tmp-1,ans);
//     }
// };



class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Step 1: Initialize the pointers
        int slow = nums[0];
        int fast = nums[0];
        
        // Step 2: Find the intersection point in the cycle
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        
        // Step 3: Find the entrance of the cycle (the duplicate)
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};