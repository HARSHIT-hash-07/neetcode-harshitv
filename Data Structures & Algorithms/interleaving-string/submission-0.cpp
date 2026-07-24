class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

        int n = s1.size();
        int m = s2.size();
        int k = s3.size();

        if(n+m != k){
            return false;
        }

        vector<vector<bool>>dp(n+1 , vector<bool>(m+1));
        dp[0][0] = true;

        for(int i = 1 ; i <= n ; i++){
            dp[i][0] = dp[i-1][0] && (s1[i-1] == s3[i-1]);
        }

        for(int j = 1 ; j <= m ; j++){
            dp[0][j] = dp[0][j-1] && (s2[j-1] == s3[j-1]);
        }

        for(int i=1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){

                bool takes1 = dp[i-1][j] && (s1[i-1] == s3[i+j-1]);
                bool takes2 = dp[i][j-1] && (s2[j-1] == s3[i+j-1]);

                dp[i][j] = takes1 || takes2;
            }
        }


        return dp[n][m];
        
    }
};
