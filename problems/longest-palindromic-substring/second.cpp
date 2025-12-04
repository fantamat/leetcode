#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrom(const string& s, int start, int end) {
        for (int i=0; i<(end-start+1) / 2; i++) {
            if (s[start+i] != s[end-i])
                return false;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int maxSize = 1;
        int maxStart = 0;

        for (int i=0; i<s.length()-1; i++) {
            for (int j=i+1; j < s.length(); j++) {
                int newSize = j-i+1;
                if (newSize <= maxSize) continue;    
                if (isPalindrom(s, i, j)) {
                    maxSize = newSize;
                    maxStart = i;
                }
            }
        }

        return s.substr(maxStart, maxSize);
    }
};