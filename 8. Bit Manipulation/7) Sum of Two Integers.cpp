/*
alculate the sum of two integers a and b, 
but you are not allowed to use the operator + and -.
Example:
Given a = 1 and b = 2, return 3.
*/

class Solution {
public:
    int getSum(int a, int b) {
        // assume that no integer overflow
    	int result = 0;
    	int totalBits = sizeof(int)*8;

    	int carry = 0;
    	int bitGetter = 1;
    	int bitSetter = 1;
    	for (int i = 0; i < totalBits; i++, bitGetter <<= 1,  bitSetter <<= 1){
    		int ai = a & bitGetter;
    		int bi = b & bitGetter;
    			
    		result |= ai ^ bi;
    		

    	}
    	return result;
    }
};