/*
Numbers can be regarded as product of its factors. For example,
8 = 2 x 2 x 2;
  = 2 x 4.
Write a function that takes an integer n and return all possible combinations of its factors.
Note:
You may assume that n is always positive.
Factors should be greater than 1 and less than n.
*/

class Solution{
private:
    void getFactors(int n, vector<int>& factors){
        for (int i = 2; i < n; i++){
            if (n % i == 0){
              factors.push_back(i);
            }
        }
    }

    void getFactors(vector<int>& factors, int idx, int n, vector<int>& v, vector<vector<int>>& result){
        if (n == 1){
            result.push_back(v);
            return;
        }
        for (int i = idx; i < factors.size() && factors[i] <= n; i++){
            if (!(n%factors[i])){
                v.push_back(factors[i]);
                getFactors(factors, i, n/factors[i], v, result);
                v.pop_back();
            }
        }
    }

public:
    vector<vector<int>> getFactors(int n) {
        if (n <= 3) return {{}};
        vector<int> factors;
        getFactors(n, factors);
        vector<vector<int>> result;
        vector<int> v;
        getFactors(factors, 0, n, v, result);
        return result;
    }
};