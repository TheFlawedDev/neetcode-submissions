class Solution {
 public:
  bool isPalindrome(string s) {
    // variable that holds the copied version of 's' without special characters
    string sS = "";

    // copy s -> sS
    for (int i = 0; i < s.size(); i++) {
      char letter = s[i];
      if (isalnum(letter)) {
        letter = static_cast<char>(std::tolower(letter));
        sS.push_back(letter);
      }
    }

    int i = 0;              // left pointer
    int j = sS.size() - 1;  // right pointer

    while (i < j) {
      char leftLetter = sS[i];
      char rightLetter = sS[j];
      if (leftLetter == rightLetter) {
        i++;
        j--;
      } else {
        return false;
      }
    }

    return true;
  }
};
