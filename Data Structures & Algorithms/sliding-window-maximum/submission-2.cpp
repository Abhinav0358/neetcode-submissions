class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // int max=nums[0];
        // int maxindex=0;
        // vector<int> ans;
        // for(int i=0; i<k; i++){
        //     if(nums[i]>=max){
        //         max=nums[i];
        //         maxindex=i;
        //     }
        // }
        // ans.push_back(max);
        // int start=0;
        // int end=k-1;
        // while(end<nums.size()){
        //     start++;
        //     end++;
        //     if(end>=nums.size())break;
        //     if(nums[end]>=max&&maxindex>=start){
        //         max=nums[end];
        //         maxindex=end;
        //     }
        //     if(maxindex<start){
        //         maxindex=findmax(nums,start,end);
        //         max=nums[maxindex];
        //     }
        //     ans.push_back(max);
        // }
        // return ans;

        deque<int> dq;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            while(!dq.empty()&&nums[dq.back()]<=nums[i])dq.pop_back();
            dq.push_back(i);
            while(dq.front() <= i-k)dq.pop_front();
            if(i>=k-1)ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
    // int findmax(vector<int> &nums, int start, int end){
    //     int max=nums[start];
    //     int maxindex=start;
    //     for(int i=start; i<=end; i++){
    //         if(nums[i]>=max){
    //             max=nums[i];
    //             maxindex=i;
    //         }
    //     }
    //     return maxindex;
    // }
};
