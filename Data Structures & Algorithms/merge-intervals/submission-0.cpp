class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int start=intervals[0][0];
        int end=intervals[0][1];
        vector<vector<int>> ans;
        for(auto& interval : intervals){
            if(end<interval[0]){
                ans.push_back({start,end});
                start=interval[0];
                end=interval[1];
                continue;
            }
            // start=min(start,interval[i][0]);
            end=max(end,interval[1]);
        }
        ans.push_back({start,end});
        return ans;
    }
};
