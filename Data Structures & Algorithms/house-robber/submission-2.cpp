class Solution {
public:

    int func(vector<int>&dp , vector<int>&nums , int i){
        if(i < 0 ) return 0;

        if(dp[i] != -1) return dp[i];

        int skip = func(dp , nums , i-1);
        int include = nums[i] + func(dp , nums , i-2);
        
        return dp[i] = max(skip , include);

    }
    int rob(vector<int>& nums) {

        int n = nums.size();
        if(n==0) return 0;

        vector<int>dp(n , -1);

        return func(dp , nums , n-1);
    }
};
