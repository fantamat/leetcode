#include <string>
#include <vector>

using namespace std;

/*
PAYPALISHIRING

P   A   H   N
A P L S I I G
Y   I   R

[
    0,    4,    8,     12, 
    1, 3, 5, 7, 9, 11, 13,
    2,    6,   10,     
]


[ 0, 4, 8,12, 1, 3, 5, 7, 9, 11, 13,  2,  6, 10]
[ 0, 1, 2, 3, 4, 5, 6, 7, 8,  9, 11, 12, 13, 14]



P     I    N
A   L S  I G
Y A   H R
P     I

[
    0,       6,      12,
    1,    5, 7,   11,13,  
    2, 4,    8,10,
    3,       9,
]





[
    i*patternLen

    1+i*patternLen 

]

*/
class Solution {
public:

    void getZigZagPosition(int idx, int numRows, int& posX, int& posY) {
        if (numRows == 1) {
            posX = idx;
            posY = 0;
        } else if (numRows == 2) {
            posX = idx / 2;
            posY = idx % 2;
        } else{
            int patternLen = numRows*2 - 2;
            int patternPos = idx % patternLen;


        }
    }

    int getEndodedPosition(int numRows, int posX, int posY) {
        return 0;
    }

    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;

        int patternLen = numRows*2 - 2;
        int cycleCount = s.length()/patternLen;

        vector<char> out(patternLen*(cycleCount+1));

        int outIdx = 0;
        for (int row=0; row<numRows; row++) {
            int lim = (s.length()+patternLen-1-row)/patternLen;
            // printf("row: %d lim: %d\n", row, lim);
            if (row==0 || row==numRows-1) {
                for (int i = 0; i < lim; i++) {
                    out[outIdx++] = s[i*patternLen+row];
                }
            } else {
                for (int i = 0; i < lim; i++) {
                    out[outIdx++] = s[i*patternLen+row];

                    if ((i+1)*patternLen-row >= s.length())
                        break;

                    out[outIdx++] = s[(i+1)*patternLen-row];
                }
            }
        }

        out[outIdx] = 0;
        
        return string(out.data(), s.length());
    }
};