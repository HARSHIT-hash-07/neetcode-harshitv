class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>>dp(n+1 , vector<int>(amount+1 , 0));

        for(int i = 0 ; i < n ; i++){
            dp[i][0] = 1;
        }

        for(int j = 1; j <= amount; j++){
            if(j % coins[0] == 0) {
                dp[0][j] = 1;
            }
        }

        for(int i = 1 ; i < n ; i++){
            for(int j = 1 ; j <= amount ; j++){
                int nottake = dp[i-1][j];
                int take = 0;
                if(j >= coins[i]){
                    take = dp[i][j-coins[i]];
                }
                dp[i][j] = take + nottake;
            }
        }

        return dp[n-1][amount];

    }
};
