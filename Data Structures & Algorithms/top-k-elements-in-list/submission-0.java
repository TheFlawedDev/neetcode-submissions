class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        int count = 1;
        HashMap<Integer, Integer> map = new HashMap<>();

        Arrays.sort(nums);

        for(int current : nums){
            if(!map.containsKey(current)){
                map.put(current, count);
            }
            if(map.containsKey(current)){
                map.put(current, map.get(current)+1);
            }
        }

        List<Map.Entry<Integer, Integer>> list = new ArrayList<>(map.entrySet());
        Collections.sort(list, (a, b) -> b.getValue() - a.getValue());
    
        // Get top k elements
        int[] result = new int[k];
        for (int i = 0; i < k; i++) {
            result[i] = list.get(i).getKey();
        }
        return result;
    }
}
