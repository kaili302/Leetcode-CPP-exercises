/*
Count the number of prime numbers less than a non-negative number, n.
*/

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        int curr = 2;
        vector<bool> isPrime(n, true);
        int count = 0;
        while (curr < n){
        	if (isPrime[curr]){
        		count++;
	        	for (int i = curr * 2; i < n; i += curr){
	        		isPrime[i] = false;
	        	}
        	}
        	curr++;
        }
        return count;
    }
};