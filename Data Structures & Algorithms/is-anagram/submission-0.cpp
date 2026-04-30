class Solution {
public:
    bool isAnagram(string s, string t) {
        // in the condition that s,t are not the same 
        // length, return false.
        // if ( s.size() != t.size()) return false;

        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());

        if(s != t) return false;
        return true;

    }
};
