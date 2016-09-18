class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
  		long base = 1;
  		while (base <= x) base *= 10;
  		base /= 10;
  		while(x > 0){
  			// compare left most and righ most digit
  			if (x/base != x%10)
  				return false;
  			x = (x % base) / 10;
  			base /= 100;
  		}
  		return true;
    }
};