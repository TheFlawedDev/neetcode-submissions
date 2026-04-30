class Solution {
    public int[] productExceptSelf(int[] nums) {
     int[] output = new int[nums.length];

     for(int i = 0; i < nums.length; i++){
        int tempProduct = 1;
        int x = 0;
        while(x < nums.length){
            if(x == i){
                x++;
            }else{
                tempProduct *= nums[x];
                x++;
            }
        }
        output[i] = tempProduct;
     }
     return output;
    }
}  
