class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),[](vector<int> &a, vector<int> &b){
            return a[1]<b[1];
        });
        int start=intervals[0][0];
        int end=intervals[0][1];
        int count=-1;
        for(auto& interval : intervals){
            // cout<<interval[0]<<" "<<interval[1]<<endl;
            if(end<=interval[0]){
                start=interval[0];
                end=interval[1];
                continue;
            }
            count++;
        }
        return count;
    }
};
