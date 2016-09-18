/*
Given an integer n, return the number of trailing zeroes in n!.
*/

class Solution {
public:
    int trailingZeroes(int n) {
    	int countZero = 0;

  		for (int i = 5; n / i >= 1; i *= 5){
  			countZero += n/i;
  		}      
  		return countZero;
    }
};