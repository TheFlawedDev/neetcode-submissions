#include <format>
#include <iterator>

class Solution {
   public:
    string encode(vector<string>& strs) {
        string buffer;

        // takes a string adds its length to the beginning followed by the string itself
        // e.g., i = "abc"
        // 'i's size is 3
        // string is now: "3abc"
        for (auto& i : strs) {
            int stringSize = i.size();
            std::format_to(std::back_inserter(buffer), "{}#{}", stringSize, i);
        }

        return buffer;
    }

    vector<string> decode(string s) {
        vector<string> res;

        int j = 0;
        string stringSize;

        while (j < s.size()) {
            // while s[j] is not "#" we can increment by 1
            // & we can create size string
            if (s[j] != '#') {
                // format_to(std::back_inserter(stringSize), s[j]);
                stringSize += s[j];
                j++;
            } else {
                int size = std::stoi(stringSize);
                // string subStr = s.substr(j + 1, j + size);
                string subStr = s.substr(j + 1, size);
                res.push_back(subStr);
                stringSize.clear();

                // move the pointer 'j' to the next string size
                j = j + size + 1;
            }
        }
        return res;
    }
};
