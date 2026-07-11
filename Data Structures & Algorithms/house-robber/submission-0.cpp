class Solution {
public:
    int rob(vector<int>& nums) {

        if (nums.empty()) {
            return 0;
        }
        
        int prev_two = 0; 
        int prev_one = 0; 
        
        for (int i : nums) {
            // Decision: skip the current house OR rob it (current + max from 2 houses ago)
            int current = max(prev_one, prev_two + i);
            
            // Move our sliding window variables forward
            prev_two = prev_one;
            prev_one = current;
        }
        
        return prev_one;
    }
};
