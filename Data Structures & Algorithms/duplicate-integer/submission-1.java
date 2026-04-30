class Solution {
    public boolean hasDuplicate(int[] nums) {
        /*
        brute force- for each index iterate through the array
        with an inner loop to look for duplicates.
        */
      /*  for(int i = 0; i< nums.length; i++){
            int temp = nums[i];
            for(int j = 0; j < nums.length; j++){
                if(nums[j] == temp && i != j){
                    return true;
                }
            }
        }
        return false;
    */

    /*in hashSet we can't have 
    duplicate values, so we can iterate through the array once
    and whe the hashMap throws an erro we found a duplicate,
    so we return true, else false.*/

    /*HashSet<Integer> set = new HashSet<>();
    for(int num : nums){
        if(!set.add(num)){
            return true;
        }else{
            set.add(num);
        }
    }
    return false;
    }*/

    /*another solution in O(nlogn) would be to sort the array, then iterate through the array, while using a temp variable we can
    compare the previous value with the current indexes value,*/
    Arrays.sort(nums);
    for (int i = 1; i < nums.length; i++){
        
        if(nums[i] == nums[i-1]){
            return true;
        }
    }   
    return false;
}
}

