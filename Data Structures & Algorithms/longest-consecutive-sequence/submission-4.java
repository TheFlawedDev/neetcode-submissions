class Solution {
    public int longestConsecutive(int[] nums) {
        if (nums.length == 0) {
            return 0; // Edge case: empty array
        }

        Set<Integer> numSet = new HashSet<>();
        for (int num : nums) {
            numSet.add(num);
        }

        int longestStreak = 0;

        for (int num : nums) {
            // Check if 'num' is the start of a sequence
            // A number is the start if (num - 1) is NOT in the set
            if (!numSet.contains(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;

                // While the next consecutive number exists in the set
                while (numSet.contains(currentNum + 1)) {
                    currentNum++;
                    currentStreak++;
                }

                longestStreak = Math.max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
}