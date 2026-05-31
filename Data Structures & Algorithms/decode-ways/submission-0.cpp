#include <string>

class Solution {
public:
    int numDecodings(std::string s) {
        // If the string is empty or starts with '0', it cannot be decoded
        if (s.empty() || s[0] == '0') {
            return 0;
        }
        
        int n = s.length();
        
        // prev2 represents dp[i-2], initially dp[0] = 1
        int prev2 = 1; 
        // prev1 represents dp[i-1], initially dp[1] = 1 (since s[0] != '0')
        int prev1 = 1; 
        
        for (int i = 2; i <= n; ++i) {
            int current = 0;
            
            // Check if the single digit s[i-1] is valid (not '0')
            if (s[i - 1] != '0') {
                current += prev1;
            }
            
            // Check if the two-digit combination s[i-2...i-1] is valid (between 10 and 26)
            int twoDigit = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (twoDigit >= 10 && twoDigit <= 26) {
                current += prev2;
            }
            
            // Move the state variables forward
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1;
    }
};