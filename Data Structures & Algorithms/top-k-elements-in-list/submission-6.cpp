class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freak;
        vector<int> res;

        for (auto& i : nums) {
            // if the key exists in the table increment its value
            if (freak.contains(i)) {
                freak[i] = freak[i] + 1;

            } else {
                // else insert i as the key with a Value of 1 to start
                freak[i] = 0;
            }
        }

        // 1. Copy map contents to vector of pairs
        std::vector<std::pair<int, int>> vec(freak.begin(), freak.end());

        // 2. Sort vector by the second element (value)
        std::sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;  // descending order
        });

        // 3. Output results
        for (int i = 0; i < k; i++) {
            res.push_back(vec[i].first);
        }

        return res;
    }
};
