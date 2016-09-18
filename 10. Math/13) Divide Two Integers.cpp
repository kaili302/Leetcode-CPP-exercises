/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
      if (divisor == 0) return INT_MAX;

      
      long dividendL = static_cast<long>(dividend);
      long divisorL = static_cast<long>(divisor);
      bool isNegatif = false;
      if ((dividendL ^ divisorL) < 0) isNegatif = true;
      dividendL = abs(dividendL);
      divisorL = abs(divisorL);

      long result = 0;
      while (dividendL >= divisorL){
        result++;
        dividendL -= divisorL;
      }   
      result = isNegatif? -result : result;
      if (result < INT_MIN || result > INT_MAX) return INT_MAX;
      return result;
    }
};