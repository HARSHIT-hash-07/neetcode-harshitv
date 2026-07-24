class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;


        for(int i = 0 ; i < nums.size() ; i++){
            sum+= nums[i];
        }

        if(sum%2!=0){
            return false;
        }

        int target = sum/2;

        vector<bool>dp(target+1 , false);
        dp[0] = true;
        // cout << dp[target] << endl; 
        // cout  << endl;
        for(int i = 0 ; i < nums.size() ; i++){
            for(int j = target ; j >= nums[i] ; j--){

                dp[j] = dp[j] || dp[j-nums[i]];
                // cout << dp[j] << " ";
            }

            // cout << endl;
         }
        
        return dp[target];
    }
};
