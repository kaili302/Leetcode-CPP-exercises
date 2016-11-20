/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

Credits:
*/


class cmp{
public:
	bool operator()(const int& num1, const int& num2)const{
		return to_string(num1) + to_string(num2) > to_string(num2) + to_string(num1);
	};
};


class Solution {
public:
    string largestNumber(vector<int>& nums) {
  		sort(nums.begin(), nums.end(), cmp{});
  		ostringstream oss;
  		for (auto& num : nums){
  		    if (!num && oss.str().empty()) continue;
  			oss << num;
  		}
  		if (oss.str().empty()) return "0";
  		return oss.str();
    }
};