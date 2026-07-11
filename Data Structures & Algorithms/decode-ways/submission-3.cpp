class Solution {
public:

    int func(vector<int>&dp , int i , string &s){

        if(i < 0) return 1;
        
        if(i == 0){
            if(s[i] == '0'){
                return 0;
            }
            else{
                return 1;
            }
        }


        if(dp[i] != -1) return dp[i];

        int ways = 0;
        if(s[i] != '0'){
            ways += func(dp , i-1 , s);
        }

        if (i >= 1 && (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))) {
            ways += func(dp, i - 2, s);
        }

        
        return dp[i] = ways;

    } 

    int numDecodings(string s) {
        if(s.empty() || s[0] == '0') return 0;

        int n = s.size();
        vector<int>dp(n , -1);

        return func(dp , n-1 , s);

    }
};