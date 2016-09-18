/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      int carry = 1;
      for (int i = digits.size() - 1; i >= 0 && carry != 0; i--){
        int sum = digits[i] + carry;
         carry = sum / 10;
         digits[i] = sum % 10;
      }
      if (carry) digits.insert(digits.begin(), carry);
      return digits;
    }
};