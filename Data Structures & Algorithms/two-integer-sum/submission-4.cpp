class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // results vector
        vector<int> rV;
        std::unordered_map<int, int> t;

        for (int i = 0; i < nums.size(); i++) {
            int comp = target - nums[i];

            // check if the table contains the complement & that the value of
            // the complement if it exists doesn't contain the same value (index)
            if (!t.contains(comp) && !t.contains(nums[i])) {
                t.insert({nums[i], i});
            }else{
                return {t[comp],i};
            }
        }
        return {};
    }
};
