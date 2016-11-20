/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.
Note: Given n will be between 1 and 9 inclusive.
*/

class Solution {
public:
    string getPermutation(int n, int k){
        if (n <= 1) return to_string(n);
        vector<long> permutations(n, 1);
        for (int i = 2; i < n; i++){
            permutations[i] = permutations[i-1] * i;
        }
        if (k > permutations[n-1] * n) return "";
    
        set<int, less<int>> nums;
        for (int i = 1; i <= n; i++){
            nums.insert(i);
        }
    
        string res;
        for (int i = n; i >= 1; i--){
            int order = (k - 1) / permutations[i-1];
            auto it = nums.begin();
            advance(it, order);
            res.push_back((*it) + '0');
            nums.erase(it);
            k = k - permutations[i-1] * order;
        }
        return res;
    }

};