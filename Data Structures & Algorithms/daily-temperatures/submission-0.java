class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int[] results = new int[temperatures.length];
        
        for(int i = 0; i < temperatures.length; i++) {
            int counter = 0;
            boolean foundWarmer = false;
            
            for(int x = i + 1; x < temperatures.length; x++) {
                counter++;
                
                if(temperatures[x] > temperatures[i]) {
                    foundWarmer = true;
                    break;
                }
            }
            
            results[i] = foundWarmer ? counter : 0;
        }
        return results;
    }
}