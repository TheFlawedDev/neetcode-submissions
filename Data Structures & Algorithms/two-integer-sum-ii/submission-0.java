class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int startPoint = 0;  // Start at 0 to check first element
        int endPoint = numbers.length-1;
        int value;
        int[] result = new int[2];

        while(startPoint < endPoint){
            value = target - numbers[startPoint];
            for(int i = endPoint; i > startPoint; i--){
                if(numbers[i] == value){  // Changed to == to find the match
                    // Add 1 to convert to 1-based indexing when returning
                    return new int[]{startPoint + 1, i + 1};
                }    
            }
            startPoint++;
        }
        return result;  // Won't reach here since solution is guaranteed
    }
}