/*
21) Ugly Number, Ugly Number II, Super Ugly Number, Find K Pairs with Smallest Sums
*/
/*
Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number.

*/
class Solution {
public:
    bool isUgly(int num) {
  		if (!num) return false;
  		if (num == 1) return true;

  		if (num % 2 == 0)
  			return isUgly(num/2);

  		if (num % 3 == 0)
  			return isUgly(num/3);

  		if (num % 5 == 0)
  			return isUgly(num/5);

  		return false;
    }
};

/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.
*/

class Solution {
public:
    int nthUglyNumber(int n) {
        
    }
};