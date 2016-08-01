/**
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
private:
    static bool compare (const Interval &lit, const Interval &rit) {
        return (lit.start == rit.start? lit.end < rit.end: lit.start < rit.start);
    }
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if (intervals.empty()) return result;
        sort(intervals.begin(), intervals.end(), compare);
        
        for (auto &interval: intervals) {
            if (result.empty() || result.back().end < interval.start) {
                result.push_back(interval);
            }else if (result.back().end <= interval.end) {
                result.back().end = interval.end;
            }
        }
        return result;
    }
};

/** 
LeetCode – Insert Interval
 
Problem:

Given a set of non-overlapping & sorted intervals, insert a new interval into the intervals (merge if necessary).

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/


class Solution {
private: 
	static bool compare(const Interval &lit, const Interval &rit) {
		return lit.start == rit.start ? lit.end < rit.end : lit.start < rit.start;
	}
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
  		vector<Interval> result;
  		sort(intervals.begin(), intervals.end(), compare);
  		for (auto &interval : intervals) {
			if (interval.end < newInterval.start) result.push_back(interval);
			else if (interval.start > newInterval.end) {
				result.push_back(newInterval);
				newInterval = interval;
			}else{
				newInterval.start = min(newInterval.start, interval.start);
				newInterval.end	= max(newInterval.end, interval.end);
			}  			
  		}
  		result.push_back(newInterval);
  		return result;
    }
};






















