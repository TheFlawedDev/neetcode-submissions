class Solution {
    public List<String> generateParenthesis(int n) {
        // StringBuilder output = new StringBuilder(); // Good thought for building strings
        // List<String> currentString = new List<>(); // This will be your final result list
        // Stack<char> parenth = new Stack<>(); // You won't directly need an explicit stack data structure here for generation.
                                               // The call stack of the recursion handles the "stacking" of states.

        // This is where you'll initialize your actual list to store results
        List<String> resultList = new ArrayList<>(); // Correct initialization for the list

        // You'll call your helper function here, passing the necessary initial values.
        // For example:
        backtrackHelper(resultList, new StringBuilder(), 0, 0, n);

        return resultList; // You'll return the list populated by the helper
    }

    // Let's refine the helper function's signature and purpose
    // It should build upon a current path and add valid complete paths to the resultList.
    // It doesn't need to return a StringBuilder itself.
    // private StringBuilder validP(int n){ // Original
    private void backtrackHelper(List<String> listToFill, StringBuilder currentCombination,
                                int openUsed, int closeUsed, int n) {
        // List<String> currentString = new List<>(); // This should be passed in (listToFill)
        // StringBuilder output = new StringBuilder(); // This should be passed in (currentCombination)

        // --- This is where the core backtracking logic will go ---

        // 1. Base Case: Have we formed a complete and valid string of 2*n characters?
        if (currentCombination.length() == n * 2) {
            listToFill.add(currentCombination.toString());
            return;
        }

        // 2. Recursive Step / Choices:

        //    Choice A: Add an open parenthesis '('
           if (openUsed < n) {
               currentCombination.append('(');
               backtrackHelper(listToFill, currentCombination, openUsed + 1, closeUsed, n);
               currentCombination.deleteCharAt(currentCombination.length() - 1); // Backtrack!
           }

        //    Choice B: Add a close parenthesis ')'
           if (closeUsed < openUsed) { // And closeUsed < n (implicitly covered if openUsed is capped by n)
               currentCombination.append(')');
               backtrackHelper(listToFill, currentCombination, openUsed, closeUsed + 1, n);
               currentCombination.deleteCharAt(currentCombination.length() - 1); // Backtrack!
           }

       // return null; // Helper will be void
    }
}