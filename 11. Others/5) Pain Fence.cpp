/*
here is a fence with n posts, each post can be painted with one of the k colors. 
You have to paint all the posts such that no more than two adjacent fence posts have the same color. 
Return the total number of ways you can paint the fence.
*/

int numWays(int n, int k) {
	if (k == 1)
		return n <= 2;
	if (n < 3) return pow(k, n);

	int sameBefore = k;
	int diffBefore = k * (k - 1);

	for (int i = 3; i <= n; i++){
		int tmp = sameBefore;
		sameBefore = diffBefore;
		diffBefore = (tmp + diffBefore) * (k - 1);
	}
	return sameBefore + diffBefore;
}