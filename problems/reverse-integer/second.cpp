#include <stdio.h>

class Solution {
public:

    int reverse(int x) {
        if (x==-2147483648)
            return 0;

        char digits[10];
        int digitCounter = 0;

        bool isNegative = (x<0);

        if (isNegative)
            x = -x;

        while (x) {
            digits[digitCounter++] = x % 10;
            x /= 10;
        }

        for (int i=0; i<digitCounter; i++) {
            printf(" %d", digits[i]);
        }
        printf("\n");

        if (digitCounter > 9) {
            const char INT_LIM_DIGITS[10] = {2,1,4,7,4,8,3,6,4,7}; // 2**31 - 1
            for (int i=0; i<10; i++) {
                if (digits[i] > INT_LIM_DIGITS[i])
                    return 0;
                if (digits[i] < INT_LIM_DIGITS[i])
                    break;
            }
        }

        int out = 0;
        unsigned int koef = 1;
        for (int i = digitCounter-1; i >= 0; i--) {
            out += digits[i]*koef;
            koef *= 10;
        }
        
        if (isNegative)
            return -out;
        return out;
    }

};