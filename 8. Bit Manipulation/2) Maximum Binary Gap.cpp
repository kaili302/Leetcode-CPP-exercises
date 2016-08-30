/*
Twitter Codility Problem – Max Binary Gap
 
Problem: Get maximum binary Gap.

For example, 9's binary form is 1001, the gap is 2.
*/


class Solution{
public:
    int getGap(int N){
        // left logic shift 
        int mask = 1 << (sizeof(int) * 8 - 1);
        int curr = sizeof(int) * 8 - 1;
        int prev = -1;
        int maxGap = 0;
        while (N != 0){
            if (mask & N){
                if (prev == -1) prev = curr;
                else {
                    maxGap = max(maxGap, prev - curr - 1);
                    prev = curr;
                }
            }
            N <<= 1;
            curr--;
        }
        return maxGap;
    }
};