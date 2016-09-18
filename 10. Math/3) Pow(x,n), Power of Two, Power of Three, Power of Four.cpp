/*
Pow(x,n), Power of Two, Power of Three, Power of Four 
*/


//Implement pow(x, n).
class Solution {
private:
    double helper(double x, int n) {
    	if (n == 0) return 1;
    	double tmp = helper(x, n/2);
    	return tmp * tmp * (n % 2 ? x : 1);
    }
public:
    double myPow(double x, int n) {
        if (n < 0) return 1 / helper(x, -n);
        return helper(x, n);
    }
};

//Given an integer, write a function to determine if it is a power of two 2^n

class Solution {
public:
    bool isPowerOfTwo(int n) {
  		return n > 0 && !(n & (n-1));
    }
};


//Given an integer, write a function to determine if it is a power of three 3^n
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 0) return false;
        if (n == 1) return true;
        if (n == 2) return false;
        return n%3 == 0 && isPowerOfThree(n/3);
    }
};


//Given an integer, write a function to determine if it is a power of four 4^n == 2^(2n)
class Solution {
public:
    bool isPowerOfFour(int n) {
    	if (n <= 0) return false;
    	if (n & (n - 1)) return false;
        int countZero = 0;
        while (n > 1){
            n >>= 1;
            countZero++;
        }
    	return countZero % 2 == 0;
    }
};

