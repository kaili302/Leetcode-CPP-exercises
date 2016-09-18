/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

class Solution {
public:
    int reverse(int x) {
  		bool isNegatif = false;
  		if (x < 0) {
  			isNegatif = true;
  			x = -x;
  		}
  		long ret = 0;
  		while (x > 0){
  			ret = ret * 10 + x % 10;
  			x /= 10;
  		}
  		ret = isNegatif ? -ret : ret;
  		if (ret < INT_MIN || ret > INT_MAX)
  		    return 0;
  		return static_cast<int>(ret);
  	}
};