/*
Problem: Get maximum binary Gap.

For example, 9's binary form is 1001, the gap is 2.
*/


class Solution{
public:
    int getGap(int N){
        int bits = sizeof(int) * 8;
        int mask = 1 << (bits - 1);
        int maxGap = 0;
        int prev = -1;
        for (int i = 0; i < bits; i++){
            if (mask & N){
                if (prev != -1) maxGap = max(maxGap, i - prev - 1);
                prev = i;
            }
            N <<= 1;
        }
        return maxGap;
    }
};


