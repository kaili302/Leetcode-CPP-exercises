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
    vector<int> getFactorsHelper(int n){
        vector<int> factors;
        for (int i = 2; i < n; i++){
            if (n % i == 0) factors.push_back(i);
        }
        return factors;
    }
    void getFactors(vector<int> &factors, int idx, int n, vector<int> &combination, vector<vector<int>> &result) {
        if (n == 0) return;
        if (n == 1) {
            result.push_back(combination);
            return;
        }
        for (int i = idx; i < factors.size() && n >= factors[i]; i++){
            if (n % factors[i] != 0) continue;
            combination.push_back(factors[i]);
            getFactors(factors, i, n/factors[i], combination, result);
            combination.pop_back();
        }
    }

public:
    vector<vector<int>> getFactors(int n) {
        if (n <= 3) return {{n}};
        vector<vector<int>> result;
        vector<int> factors = getFactorsHelper(n);
        vector<int> combination;
        getFactors(factors, 0, n, combination, result);
        return result;
    }
};
