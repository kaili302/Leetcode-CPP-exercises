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
      // use two bits to present a DNA nucleotide
      // 10-letter-long sequences use 20 bits
      unordered_map<char, uint32_t> dict;
      dict.emplace('A', 0); dict.emplace('C', 1);
      dict.emplace('G', 2); dict.emplace('T', 3);
      
      unordered_set<uint32_t> sequences;
      unordered_set<string> result;
      uint32_t sequence  = 0;
      uint32_t mask = 0x000FFFFF;

      for (int i = 0; i < s.length(); i++){
        sequence |= dict[s[i]];
        if (i >= 9){
          if (sequences.count(sequence)){
            result.insert(s.substr(i - 9, 10));
          }
          sequences.insert(sequence);
        }
        sequence <<= 2;
        sequence &= mask;

      }
      return {result.begin(), result.end()};
    }
};