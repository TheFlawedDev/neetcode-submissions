class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> res;

    for (int i = 0; i < numbers.size(); i++) {
      int dif = target - numbers[i];

      auto lower = lower_bound(numbers.begin() + i + 1, numbers.end(), dif);
      if (lower != numbers.end() && *lower == dif) {
        int index = lower - numbers.begin();
        res.push_back(i+1);
        res.push_back(index+1);
      }
    }
    if (res.empty()) {
      return res;
    } else {
      return res;
    }
  }
};
