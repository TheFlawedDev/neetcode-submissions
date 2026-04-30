class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s == null || s.length() == 0) { // Handle empty or null string
            return 0;
        }

        Set<Character> charSet = new HashSet<>(); // Using Character for clarity
        int maxLength = 0;
        int left = 0; // Left pointer of the sliding window

        // The 'right' pointer will be the 'i' in your loop
        for (int right = 0; right < s.length(); right++) {
            // If the character at 'right' is already in our set,
            // it means we have a duplicate in our current window.
            // We need to shrink the window from the 'left' until the duplicate is removed.
            while (charSet.contains(s.charAt(right))) {
                charSet.remove(s.charAt(left)); // Remove character from the left
                left++; // Move the left pointer forward
            }

            // Now that the window is valid (no duplicates), add the current character
            charSet.add(s.charAt(right));

            // Update the maximum length found so far
            // The current window length is (right - left + 1)
            maxLength = Math.max(maxLength, right - left + 1);
        }

        return maxLength;
    }
}