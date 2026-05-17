class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // nlog(n)
        // sort(nums.begin(),nums.end());
        // return nums[nums.size()-k];


        // nlogk

        priority_queue<int, vector<int>, greater<int> > pq;
        for(int i=0; i<nums.size(); i++){
            pq.push(nums[i]);  //logk
            if(i>=k)pq.pop();   //logk
        }
        return pq.top();
    }
};
