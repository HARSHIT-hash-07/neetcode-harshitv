class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        std::vector<int> sub;
        
        for (int num : nums) {
            // If sub is empty or num is greater than the last element, append it.
            if (sub.empty() || num > sub.back()) {
                sub.push_back(num);
            } 
            else {
                // Otherwise, use binary search to find the first element >= num
                // and replace it.
                auto it = std::lower_bound(sub.begin(), sub.end(), num);
                *it = num; 
            }
        }
        
        // The length of the sub array is the length of the LIS.
        return sub.size();
        
    }
};
