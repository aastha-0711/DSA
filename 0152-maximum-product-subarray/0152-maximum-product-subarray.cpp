#include <algorithm>
#include <climits>

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int producty = nums[0]; 
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int product = nums[i];
            producty = max(producty, product);
            
            for (int j = i + 1; j < n; j++) {
                product *= nums[j];
                producty = max(producty, product);
            }
        }
        
        return producty;
    }
};