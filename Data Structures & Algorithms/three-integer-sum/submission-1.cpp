class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());  // we want to sort the input vector 1st.
    vector<vector<int>> res;         // vector to hold results

    for (int i = 0; i < nums.size(); i++) {
      // if the current value is greater than ZERO than the left
      // & right pointers will also be positive and will never sum to ZERO.
      if (nums[i] > 0) break;
      // if we dont check for that the current index is greater than ZERO
      // then the next condition will be out of range.
      if (i > 0 && nums[i] == nums[i - 1]) continue;

      int l = i + 1, r = nums.size() - 1;
      while (l < r) {
        int sum = nums[i] + nums[l] + nums[r];
        if (sum > 0) {
          r--;
        } else if (sum < 0) {
          l++;
        } else {
          res.push_back({nums[i], nums[l], nums[r]});
          r--;
          l++;
          while (l < r && nums[l] == nums[l - 1]) {
            l++;
          }
        }
      }
    }
    return res;
  }
};
