class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] lh = new int[nums.length];
        int[] rh = new int[nums.length];
        int[] output = new int[nums.length];
        int temp = 1;

        for(int i = 0; i < nums.length; i++){
            if(i == 0){
                lh[0] = 1;
            }else {
                temp *= nums[i-1];
                lh[i] = temp;
            }
        }

        temp = 1;
        for(int i = nums.length-1; i >= 0; i--){
            if(i == nums.length-1){
                rh[i] = 1;
            }else {
                temp *= nums[i+1];
                rh[i] = temp;
            }
        }
        int i = 0;
        for(int cur: lh){
            output[i] = lh[i] * rh[i];
            i++;
        }

        return output;
    }
}  
