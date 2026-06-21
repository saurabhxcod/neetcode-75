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
    static bool comp(const Interval& a,Interval& b){
        return a.end<b.end;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n=intervals.size();
        if(n<=1) return true;
        sort(intervals.begin(),intervals.end(),comp);
        int prevEnd=intervals[0].end;
        for(int i=1;i<n;i++){
            if(intervals[i].start<prevEnd){
                return false;
            }
            prevEnd=intervals[i].end;
        }
        return true;
    }
};
