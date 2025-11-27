#include <string>
using namespace std;


#define MAX_CHARS 128
    
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool charCount[MAX_CHARS];

        int startIdx = 0;
        int endIdx = 0;
        int maxLen = 0;

        for (; endIdx<s.size(); endIdx++) {
            if (charCount[s[endIdx]]) {
                // update max if needed
                int currentLen = endIdx - startIdx;
                if (currentLen > maxLen)
                    maxLen = currentLen;

                // remove prefix that contains character that is present
                for (startIdx; startIdx < endIdx; startIdx++) {
                    // stop if is the same
                    if (s[startIdx] == s[endIdx]) {
                        startIdx++;
                        break;
                    }
                    charCount[s[startIdx]] = false; // remove from storage
                }
                
            } else {
                // continue adding
                charCount[s[endIdx]] = true;
            }

        }
        int currentLen = endIdx - startIdx;
        if (currentLen > maxLen)
            maxLen = currentLen;

        return maxLen;
    }
};