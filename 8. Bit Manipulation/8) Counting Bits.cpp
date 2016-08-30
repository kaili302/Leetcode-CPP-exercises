/*
Given a non negative integer number num. For every numbers i in 
the range 0 ≤ i ≤ num calculate the number of 1's in their binary 
representation and return them as an array. For num = 5 you should return [0,1,1,2,1,2].

It is very easy to come up with a solution with run time O(n*sizeof(integer)). 
But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
*/

class Solution {
public:
    vector<int> countBits(int num) {
  		// 找规律, 有点像gray code用到对称的方法
  		vector<int> result;
  		result.reserve(num + 1);
  		result.push_back(0);

  		int j = 1;
  		while (j <= num){
  			int size = result.size();
  			for (int i = 0; i < size && j <= num; i++, j++){
  				result.push_back(result[i] + 1);
  			}
  		}
  		return result;
    }
};

