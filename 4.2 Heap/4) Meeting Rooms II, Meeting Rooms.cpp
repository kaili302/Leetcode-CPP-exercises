/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] 
(si < ei), determine if a person could attend all meetings. 
For example, Given [[0, 30],[5, 10],[15, 20]], return false. 
If a person can attend all meetings, there must not be any overlaps between any meetings. 
After sorting the intervals, we can compare the current end and next start.
*/

struct Interval{
	int start;
	int end;
};


class Solution{
private:
	static bool compareIntervals(const Interval &it1, const Interval &it2){
		return it1.start < it2.start;
	}
public:
	bool canAttendMeetings(vector<Interval> intervals) {
		sort(intervals.begin(), intervals.end(), compareIntervals);

		for (int i = 1; i < intervals.size(); i++){
			if (intervals[i-1].end > intervals[i].start)
				return false;
		}
		return true;
	}
};

/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] 
find the minimum number of conference rooms required.
*/


class Solution{
private:
	static bool compareTime(const int &t1, const int &t2){
		return abs(t1) < abs(t2);
	}
public:
	int minMeetingRooms(vector<Interval> intervals) {
		vector<int> timePoints;
		for (auto &interval : intervals){
			timePoints.push_back(interval.start);
			timePoints.push_back(-interval.end);
		}
		sort(timePoints.begin(), timePoints.end(), compareTime);

		int countRooms = 0;
		int minRooms = 0;
		for (auto &timePoint : timePoints){
			//cout << timePoint << " ";
			if (timePoint >=0 ) countRooms++;
			else countRooms--;
			minRooms = max(minRooms, countRooms);
		}
		return minRooms;
	}
};