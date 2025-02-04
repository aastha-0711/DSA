#include <vector>
using namespace std;
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0; // Handle empty array case

    int i = 0; // Pointer for the position of unique elements

    for (int j = 1; j < nums.size(); j++) {
      if (nums[j] != nums[i]) { // Compare current element with the last unique element
        i++;                    // Move to the next position
        nums[i] = nums[j];      // Place the current unique element
      }
    }

    return i + 1; // Length of unique elements is (index + 1)
  }
};
