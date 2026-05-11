#include <limits>
class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_map<int, int> copyOfNums;

    int lowestVal = std::numeric_limits<int>::max();
    for (auto& number : nums) {
      if (number < lowestVal) {
        lowestVal = number;
      }
      // number isn't in the map
      if (copyOfNums.find(number) == copyOfNums.end()) {
        copyOfNums[number] = 1;
      } else {
        copyOfNums[number] += 1;
      }
    }

    int numsSize = nums.size();  // number of elements in the nums array
    int arraySize = 0;           // tracks when we stop incrementing 'current'
    int current = lowestVal;
    int runningCount = 0;
    int maxCount = 0;

    while (arraySize < numsSize) {
      if (copyOfNums.contains(current)) {
        arraySize += copyOfNums.at(current);
        runningCount += 1;
        current += 1;
      } else {
        current += 1;
        if (runningCount > maxCount) {
          maxCount = runningCount;
        }
        runningCount = 0;
      }
    }
    // Check one final time in case the longest sequence goes to the end
    if (runningCount > maxCount) {
      maxCount = runningCount;
    }

    return maxCount;
  }
};
