/*
Given a non negative integer number num. For every numbers i in 
the range 0 ≤ i ≤ num calculate the number of 1's in their binary 
representation and return them as an array. For num = 5 you should return [0,1,1,2,1,2].

It is very easy to come up with a solution with run time O(n*sizeof(integer)). 
But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
*/

class Solution {
public:
    vector<int> countBits(int num) {
      vector<int> result{0};
      for (int i = 1; i <= num; i++){
        int size = result.size();
        for (int j = 0; j < size && j + size <= num; j++){
          result.push_back(result[j] + 1);
        }
      }
      return result;
    }
};
