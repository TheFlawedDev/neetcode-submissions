class Solution {
    public boolean isPalindrome(String s) {
        String noSpaces = s.replace(" ", "");
        char[] charArray = noSpaces.toLowerCase().toCharArray();
        int x = charArray.length-1;

        for(int i = 0; i < x; i++){
             // Skip non-alphanumeric from left
            while(i < x && !Character.isLetterOrDigit(charArray[i])) {
                i++;
            }
            // Skip non-alphanumeric from right
            while(i < x && !Character.isLetterOrDigit(charArray[x])) {
                x--;
            }
            // Now we have letters/digits at both i and x
            if(i < x && charArray[i] != charArray[x]) {
                return false;
            }
            x--;
        }
        return true;
    }
}
