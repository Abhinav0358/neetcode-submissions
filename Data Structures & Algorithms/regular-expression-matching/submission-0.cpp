#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = p.size();
        int n = s.size();

        // dp[i][j] = does p[0...i-1] match s[0...j-1]?
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // Base case: empty pattern matches empty string
        dp[0][0] = true;

        // Base case: patterns like a*, a*b*, a*b*c* can match empty string (j = 0)
        for (int i = 2; i <= m; i++) {
            if (p[i - 1] == '*') {
                dp[i][0] = dp[i - 2][0];
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[i - 1] == '.' || p[i - 1] == s[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[i - 1] == '*') {
                    // 1. Match 0 occurrences of p[i-2]
                    dp[i][j] = dp[i - 2][j];

                    // 2. Match 1 or more occurrences if p[i-2] matches s[j-1]
                    if (p[i - 2] == '.' || p[i - 2] == s[j - 1]) {
                        dp[i][j] = dp[i][j] || dp[i][j - 1];
                    }
                }
            }
        }

        return dp[m][n];
    }
};