#include <stdio.h>

#define CHECKLIM 10000000



class Solution {
public:
    int reverse(int x) {
        unsigned int out = 0;
        
        if (x==-2147483648)
            return 0;

        bool isNegative = (x<0);

        if (isNegative)
            x = -x;

        unsigned int prev;
        while (x) {
            unsigned int digit = x % 10;
            x /= 10;
            prev = out;
            out = out*10+digit;

            printf("Prev: %d Out: %d\n", prev, out);

            if ((prev > CHECKLIM) && ( prev % CHECKLIM != (out/10) % CHECKLIM)) {
                // overflow
                return 0;
            }
        }

        printf("out: %d\n", out);

        if (out > 2147483647)
            return 0;
        
        if (isNegative)
            return -out;
        return out;
    }
};