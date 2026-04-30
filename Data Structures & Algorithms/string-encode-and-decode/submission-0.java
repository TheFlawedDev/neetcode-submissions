class Solution {
    private StringBuilder resultStr;
    //private finalStr;

    public String encode(List<String> strs) {
        resultStr = new StringBuilder();

        for(String str: strs){
            int length = str.length();
            String num = Integer.toString(length);
            resultStr.append(num).append("#").append(str);
        }
        return resultStr.toString();
    }

    public List<String> decode(String str) {
        List<String> result = new ArrayList<>();
        int i = 0;

        while (i < str.length()) {
            // Find the next `#` to extract the length
            int hashIndex = str.indexOf('#', i);
            int length = Integer.parseInt(str.substring(i, hashIndex));

            // Extract the string of the given length
            int start = hashIndex + 1;
            int end = start + length;
            String decodedString = str.substring(start, end);

            // Add the decoded string to the result list
            result.add(decodedString);

            // Move the pointer to the next encoded part
            i = end;
        }

        return result;
    }
}
