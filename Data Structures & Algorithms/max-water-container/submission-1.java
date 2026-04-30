class Solution {
    public int maxArea(int[] heights) {
        int i = 0;
        int j = heights.length - 1;
        int maxContainerLevel = 0;

        while (i < j) {
            int height = Math.min(heights[i], heights[j]);
            int width = j - i;
            int area = height * width;
            maxContainerLevel = Math.max(maxContainerLevel, area);

            // Move the pointer pointing to the shorter line
            if (heights[i] < heights[j]) {
                i++;
            } else {
                j--;
            }
        }

        return maxContainerLevel;
    }
}
