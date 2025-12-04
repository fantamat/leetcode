#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        vector<int> palindromStarts = {};
        vector<int> palindromSizes = {};

        int maxCandidateSize = 0;
        int maxCandidateStart = 0;
        
        for (int i=0; i < s.length() - 1; i++) {
            if (s[i] == s[i+1]) {
                palindromStarts.push_back(i);
                palindromSizes.push_back(2);
                if (maxCandidateSize < 2) {
                    maxCandidateSize = 2;
                    maxCandidateStart = i;
                }
            }
            if (i == s.length() - 2) break;
            if (s[i] == s[i+2]) {
                palindromStarts.push_back(i);
                palindromSizes.push_back(3);

                if (maxCandidateSize < 3) {
                    maxCandidateSize = 3;
                    maxCandidateStart = i;
                }
            }
        }

        if (palindromStarts.empty()) {
            return s.substr(0,1);
        }

        bool grown = true;
        while (grown) {
            grown = false;
            for (int i=0; i<palindromStarts.size(); i++) {
                if (palindromStarts[i] <= 0) continue;

                if (palindromStarts[i] + palindromSizes[i] > s.length()) {
                    palindromStarts[i] = -1;
                } else if (s[palindromStarts[i]-1] == s[palindromStarts[i]+palindromSizes[i]]) {
                    grown = true;
                    palindromStarts[i] -= 1;
                    palindromSizes[i] += 2;

                    if (maxCandidateSize < palindromSizes[i]) {
                        maxCandidateSize = palindromSizes[i];
                        maxCandidateStart = palindromStarts[i];
                    }
                }
                
            }
        }

        return s.substr(maxCandidateStart, maxCandidateSize);
    }
};