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
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(),[](Interval &a, Interval &b){
            return a.start<b.start;
        });
        
        int start=intervals[0].start;
        int end=intervals[0].end;

        for(int i=1; i<intervals.size(); i++){
            if(end<=intervals[i].start){
                start=intervals[i].start;
                end=intervals[i].end;
                continue;
            }
            return false;
        }
        return true;
    }
};
