class KthLargest {
public:

// using a max heap - inefficient - add elem, pop k-1, see top, put them back

// int target;
// priority_queue<int> pq;
//     KthLargest(int k, vector<int>& nums) {
//         target=k;
//         pq=priority_queue<int>(nums.begin(),nums.end());
//     }
//     int add(int val) {
//         pq.push(val);
//         vector<int>vec;
//         for(int i=0; i<target-1; i++){
//             vec.push_back(pq.top());
//             pq.pop();
//         }
//         int ans=pq.top();
//         for(int i=target-2; i>=0; i--){
//             pq.push(vec[i]);
//             vec.pop_back();
//         }
//         return ans;
//     }


// take k largest elements, the top (min) is kth largest, add it, remove top, return top
// intuition of  

int target;
int count=0;
priority_queue<int,vector<int>,greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        target=k;
        for(int i=0; i<nums.size(); i++){
            pq.push(nums[i]);
            count++;
            if(i>k-1){
                pq.pop();
                count--;
                }
        }
    }
    int add(int val) {
        pq.push(val);
        count++;
        if(count>target)pq.pop();
        return pq.top();
    }
};
