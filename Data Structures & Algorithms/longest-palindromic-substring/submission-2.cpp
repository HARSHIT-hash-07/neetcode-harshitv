#include <string>
#include <vector>
#include <algorithm> // Required for std::reverse and std::max

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        // 1. Declare the missing string length variable
        int n = s.length();
        
        // 2. Correctly copy and reverse the string using std::reverse
        string s2 = s;
        reverse(s2.begin(), s2.end());

        // 3. Declare the tracking variables that were missing
        int max_len = 0;
        int ending_index = 0;

        // 4. Initialize the 2D DP table
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    
                    if (dp[i][j] > max_len) {
                        if (i - dp[i][j] == n - j) { 
                            max_len = dp[i][j];
                            ending_index = i; 
                        }
                    }
                } else {
                    dp[i][j] = 0; 
                }
            }
        }

        return s.substr(ending_index - max_len, max_len);
    }
};