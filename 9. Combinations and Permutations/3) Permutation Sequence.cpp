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
    string getPermutation(int n, int k) {
        string result;
        if (k <= 0 || n <= 0) return result;
        vector<int> factorial(n + 1);
        list<int> mem;
        for (int i = 1; i <= n; i++){
            if (i == 1) factorial[i] = 1;
            else factorial[i] = i * factorial[i-1];
            mem.push_back(i);
        }

        for (int i = n; i >= 1; i--){
            if (mem.size() == 1){
                result.push_back(mem.front() + '0');
                break;
            }

            int digit = k / factorial[i-1];
            k %= factorial[i-1];
            list<int>::iterator it = mem.begin();
            if (k == 0) advance(it, digit - 1);    
            else advance(it, digit);
            result.push_back(*it + '0');
            mem.erase(it);

            if (k == 0){
                while (mem.size()){
                    result.push_back(mem.back() + '0');
                    mem.pop_back();
                }
                break;
            }
        }
        return result;
    }
};
