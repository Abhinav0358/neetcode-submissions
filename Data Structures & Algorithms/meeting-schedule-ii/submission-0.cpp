/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> starttimes;
        vector<int> endtimes;

        for(auto & interval : intervals){
            starttimes.push_back(interval.start);
            endtimes.push_back(interval.end);
        }
        sort(starttimes.begin(), starttimes.end());
        sort(endtimes.begin(), endtimes.end());

        int start=0;
        int end=0;
        int rooms=0;
        int maxrooms=0;
        while(start<starttimes.size()){
            if(starttimes[start]<endtimes[end]){
                // cout<<starttimes[start]<<" "<<endtimes[end]<<" ";
                rooms++;
                start++;
            }else{
                 start++;
                 end++;
            }
        }

        return rooms;

    }
};
