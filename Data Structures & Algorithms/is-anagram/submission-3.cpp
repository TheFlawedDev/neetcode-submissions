class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;

    // store the strings s,t in hashtable
    std::unordered_map<char, int> sMap;
    std::unordered_map<char, int> tMap;

    // s table
    for (auto& letter : s) {
      if (sMap.contains(letter)) {
        sMap[letter] = sMap[letter] + 1;
      }else{
        sMap[letter] = 1;
      }
    }
    // t table
    for (auto& tletter : t) {
      if (tMap.contains(tletter)) {
        tMap[tletter] = tMap[tletter] + 1;
      }else{
        tMap[tletter] = 1;
      }
    }

    for (auto& letterMap : sMap) {
      // check if current letter exist in both tables & values match
      if (tMap.contains(letterMap.first) && (sMap[letterMap.first] != tMap[letterMap.first]) ||
          !tMap.contains(letterMap.first)) {
        return false;
      }
    }
    return true;
  }
};
