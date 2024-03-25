#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int index = 0; // Index to place the next element not equal to val
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[index++] = nums[i]; // Place the element at index and then increment index
            }
        }
        
        return index; // Index represents the count of elements not equal to val
    }
};