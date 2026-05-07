class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> prefix(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                prefix[i] = nums[i];
            } else {
                prefix[i] = nums[i] * prefix[i - 1];
            }
        }

        std::vector<int> postfix(nums.size());
        for (int j = nums.size() - 1; j > -1; j--) {
            if (j == nums.size() - 1) {
                postfix[j] = nums[j];
            } else {
                postfix[j] = nums[j] * postfix[j + 1];
            }
        }

        vector<int> res(nums.size());
        for (int k = 0; k < nums.size(); k++) {
            // at index 0 take only from postfix +1
            if (k == 0) {
                res[k] = postfix[k + 1];
                continue;
            } else

                // when we've reached the end of nums only take the
                // the prefix -1
                if (k == nums.size() - 1) {
                    res[k] = prefix[k - 1];
                    continue;
                } else {
                    res[k] = (prefix[k - 1] * postfix[k + 1]);
                }
        }

        return res;
    }
};
