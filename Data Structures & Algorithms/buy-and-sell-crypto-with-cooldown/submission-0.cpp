class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;

        vector<int> held(n, 0);
        vector<int> sold(n, 0);
        vector<int> rest(n, 0);

        held[0] = -prices[0]; 
        sold[0] = 0;        
        rest[0] = 0;          

        for (int i = 1; i < n; i++) {
            // Keep holding what we had, OR buy today (coming from rest)
            held[i] = max(held[i - 1], rest[i - 1] - prices[i]);
            
            // The only way to sell today is to have held a stock yesterday
            sold[i] = held[i - 1] + prices[i];
            
            // Keep resting, OR we are forced to rest because we sold yesterday
            rest[i] = max(rest[i - 1], sold[i - 1]);
        }

        // The max profit on the final day will always be a state where our hands are empty
        return max(sold[n - 1], rest[n - 1]);
    }
};