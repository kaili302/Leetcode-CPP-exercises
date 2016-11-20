class Solution {
public:
	/* f(n)=f(n-1) + f(n-2)*f(1) + f(n-3)*f(2) +...+ f(2)*f(n-3) + f(1)*f(n-2) +f(n-1) */
    int numTrees(int n) {
    	std::vector<int> numTrees(n+1, 0);
    	numTrees[0] = 1;
    	for (int i=1; i<=n; i++) {
    		numTrees(i, numTrees);
    	}
    	return numTrees[n];
    }

    int numTrees(int n, std::vector<int>& numTrees) {
		for (int i=0; i<n; i++) {
			numTrees[n] += numTrees[n-1-i]*numTrees[i];
		}
    }
};