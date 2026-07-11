class Solution {
public:

    int robfrom(vector<int>& dp, const vector<int>& nums, int i) {
        if (i < 0) return 0;

        if (dp[i] != -1) return dp[i];

        int skip = robfrom(dp, nums, i - 1);

        int rob = nums[i] + robfrom(dp, nums, i - 2);

        return dp[i] = max(skip, rob);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> v1;
        vector<int> v2;

        for (int i = 0; i < n - 1; i++) {
            v1.push_back(nums[i]);
        }

        for (int i = 1; i < n; i++) {
            v2.push_back(nums[i]);
        }

        vector<int> dp1(v1.size(), -1);
        vector<int> dp2(v2.size(), -1);

        int ans1 = robfrom(dp1, v1, v1.size() - 1);
        int ans2 = robfrom(dp2, v2, v2.size() - 1);

        return max(ans1, ans2);
    }
};
