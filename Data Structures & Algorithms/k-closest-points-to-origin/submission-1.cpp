class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> pq;
        int count=0;

        for(auto vec: points){
            int dist=pow(vec[0],2)+pow(vec[1],2);
            pair<int,vector<int>> newcord={dist,vec};
            pq.push(newcord);
            count++;
            if(count>k){
                cout<<pq.top().first;
                pq.pop();
                count--;
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
