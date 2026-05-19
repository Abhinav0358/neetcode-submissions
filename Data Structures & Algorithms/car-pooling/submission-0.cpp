struct compare{
    bool operator()(const vector<int> &a, const vector<int> &b){
        return a[2]>b[2];
    }
};
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // umm
        // run a simulation
        // For a particular E coordinate 
        // put as many trips as possible 
        // the trips with the min end coordinate should come out if applicable
        // after each iteration the passengers should be less than 5

        sort(trips.begin(), trips.end(), [](const vector<int>&a, const vector<int> &b){
            return a[1]<b[1];
        });

        priority_queue<vector<int>, vector<vector<int>>, compare> pq;

        int ecoord=trips[0][1];
        pq.push(trips[0]);
        int count=1;
        int passengers=trips[0][0];
        while(count<trips.size()){
            while(count<trips.size()&&trips[count][1]<=ecoord){
                pq.push(trips[count]);
                passengers+=trips[count][0];
                count++;
            }
            while(pq.top()[2]<=ecoord){
                passengers-=pq.top()[0];                
                pq.pop();
            }
            if(passengers>capacity)return false;
            if(count<trips.size())ecoord=trips[count][1];
            // if(count<trips.size())ecoord=pq.top()[2];
        }
    return true;
    }
};