/*
All DNA is composed of a series of nucleotides abbreviated as 
A, C, G, and T,  for example: "ACGAATTCCG".

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
*/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
      unordered_map<char, uint32_t> DNAMap{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
      unordered_map<int, string> hashmap;
      unordered_set<string> result;

      int sequence = 0;
      int mask = ~((~0) << 20);
      for (int i = 0; i < s.size(); i++){
        sequence = (sequence << 2) + DNAMap[s[i]];
        if (i >= 9){
          sequence = mask & sequence;
          if (hashmap.count(sequence)){
            result.insert(hashmap[sequence]);
          }else{
            hashmap.insert({sequence, s.substr(i - 9, 10)});
          }
        }
      }
      return {result.begin(), result.end()};
    }
};