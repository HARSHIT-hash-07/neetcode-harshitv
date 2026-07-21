class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        
        int n = s.length();
        vector<bool> dp(n + 1, false);

        dp[0] = true; 
        
        // i represents the end of the substring we are checking
        for (int i = 1; i <= n; i++) {
            // j represents the start of the substring we are checking
            for (int j = 0; j < i; j++) {
                // If the string up to 'j' is valid (dp[j] is true) 
                // AND the substring from 'j' to 'i' is in the dictionary...
                if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                    dp[i] = true; 
                    break; 
                }
            }
        }
        
        return dp[n];
        
    }
};
