class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // validates rule 1 & 2
        for (int rows = 0; rows < board.size(); rows++) {
            unordered_set<char> seen;

            for (int cols = 0; cols < board.size(); cols++) {
                char value = board[rows][cols];

                if (value == '.') continue;

                if (seen.contains(value)) {
                    cout << "Duplicate in row " << rows << endl;

                    return 0;

                } else {
                    seen.insert(value);
                }
            }
        }

        for (int col = 0; col < 9; col++) {
            unordered_set<char> seen;

            for (int row = 0; row < 9; row++) {
                char value = board[row][col];

                if (value == '.') continue;

                if (seen.contains(value)) {
                    cout << "Duplicate in column " << col << endl;
                    return 0;
                }

                seen.insert(value);
            }
        }

        for (int boxRow = 0; boxRow < 9; boxRow += 3) {
            for (int boxCol = 0; boxCol < 9; boxCol += 3) {
                unordered_set<char> seen;

                // Scan inside the current 3x3 box
                for (int row = boxRow; row < boxRow + 3; row++) {
                    for (int col = boxCol; col < boxCol + 3; col++) {
                        char value = board[row][col];

                        if (value == '.') continue;

                        if (seen.find(value) != seen.end()) {
                            return 0;  // duplicate found
                        }

                        seen.insert(value);
                    }
                }
            }
        }

        return 1;
    }
};
