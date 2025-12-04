#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int maxStart = 0;
        int maxLen = 1;
        
        for (int i = 0; i < s.length(); i++) {
            // Expand around center for odd-length palindromes
            int len1 = expandAroundCenter(s, i, i);
            // Expand around center for even-length palindromes
            int len2 = expandAroundCenter(s, i, i + 1);
            
            int len = max(len1, len2);
            
            if (len > maxLen) {
                maxLen = len;
                maxStart = i - (len - 1) / 2;
            }
        }
        
        return s.substr(maxStart, maxLen);
    }
    
private:
    int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};