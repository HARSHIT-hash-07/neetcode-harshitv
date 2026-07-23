class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        int n = nums.size();
        
        for(int num : nums) {
            totalSum += num;
        }

        if (abs(target) > totalSum || (target + totalSum) % 2 != 0) {
            return 0;
        }

        int subsetSum = (target + totalSum) / 2;

        vector<vector<int>> dp(n + 1, vector<int>(subsetSum + 1, 0));
        
        // Base case: There is exactly 1 way to make a sum of 0 using 0 elements (pick nothing)
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= subsetSum; j++) {
                
                int nottake = dp[i - 1][j];
                
                int take = 0;
                if (j >= nums[i - 1]) {
                    take = dp[i - 1][j - nums[i - 1]];
                }
                
                dp[i][j] = take + nottake;
            }
        }

        return dp[n][subsetSum];
        
    }
};
