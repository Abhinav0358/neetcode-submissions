class KthLargest {
public:

int target;
priority_queue<int> pq;
    KthLargest(int k, vector<int>& nums) {
        target=k;
        pq=priority_queue<int>(nums.begin(),nums.end());
    }
    int add(int val) {
        pq.push(val);
        vector<int>vec;
        for(int i=0; i<target-1; i++){
            vec.push_back(pq.top());
            pq.pop();
        }
        int ans=pq.top();
        for(int i=target-2; i>=0; i--){
            pq.push(vec[i]);
            vec.pop_back();
        }
        return ans;
    }
};
