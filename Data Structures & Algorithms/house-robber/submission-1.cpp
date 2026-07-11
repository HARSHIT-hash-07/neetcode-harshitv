class Solution {
public:
    int rob(vector<int>& nums) {

        if (nums.empty()) {
            return 0;
        }
        
        int prev_two = 0; 
        int prev_one = 0; 
        
        for(int i = 0 ; i < nums.size() ; i++){

            int current = max(prev_one ,  prev_two + nums[i]);

            prev_two = prev_one;
            prev_one = current;
        }
        
        return prev_one;
    }
};
