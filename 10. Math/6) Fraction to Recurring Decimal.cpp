/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
*/

class Solution {
public:
    string fractionToDecimal(int numer, int denom) {
      if (!denom) return "";

      long numerator = static_cast<long>(numer);
      long denominator = static_cast<long>(denom);

      ostringstream oss;
      oss << ((numerator * denominator) < 0? "-" : "");

      numerator = abs(numerator);
      denominator = abs(denominator);
      oss << (numerator / denominator);

      numerator %= denominator;
      if (!numerator) return oss.str();
      
      oss << '.';

      unordered_map<long, long> hashmap;
      int position = oss.str().size();
      hashmap.insert({numerator, position});
      while (numerator){
        numerator *= 10;
        oss << (numerator / denominator);
        numerator %= denominator;
        if (hashmap.count(numerator)) {
          return oss.str().substr(0, hashmap[numerator]) + "(" + oss.str().substr(hashmap[numerator]) + ")";
        }
        position++;
        hashmap.insert({numerator, position});

      }

      return oss.str();
    }
};