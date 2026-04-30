#include <algorithm>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // assuming the array is not sorted
        // if we sort the array we can use a sliding window
        // a sorted array will cause duplicates to appear next to each
        // other.
        sort(nums.begin(), nums.end());

        // When nums[i] == nums[i+1] we found a duplicate and can return false.
        int i = 0;

        for (std::size_t i = 0; i < nums.size(); ++i)
        {
            // When nums[i] != nums[i+1] we can increment i by 1.
            if(nums[i] != nums[i+1])
            {
                i++;
            }else
            {
                // When nums[i] == nums[i+1] we found a duplicate and can return true.
                return true;
            }
        }
        return false;
    }
};