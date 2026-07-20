class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        double ans = nums[0]; 
        
        double prefix = 1;
        double suffix = 1;
        
        for (int i = 0; i < n; i++) {
            // If we hit a 0, reset the product to 1 to start a fresh subarray
            if (prefix == 0) prefix = 1;
            if (suffix == 0) suffix = 1;

            prefix *= nums[i];

            suffix *= nums[n - 1 - i];
            
            ans = max({ans, prefix, suffix});
        }
        
        return ans;
        
    }
};
