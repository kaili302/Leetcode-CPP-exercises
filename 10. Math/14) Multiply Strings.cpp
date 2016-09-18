/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note:
The numbers can be arbitrarily large and are non-negative.
Converting the input string to integer is NOT allowed.
You should NOT use internal library such as BigInteger.
*/


class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector<int> result(num1.size() + num2.size(), 0);

        for (int i1 = 0; i1 < num1.size(); i1++){
          for (int i2 = 0; i2 < num2.size(); i2++){
            int product = (num1[i1] - '0') * (num2[i2] - '0') + result[i1+i2];
            result[i1+i2] = product % 10;
            result[i1+i2+1] += product / 10;
          }
        }

        string multiplication;
        for (int i = result.size() - 1; i >= 0; i--){
          if (result[i] == 0 && multiplication.empty() && i != 0) continue;
          multiplication.push_back(static_cast<char>(result[i]+'0'));
        }
        return multiplication;
    }
};