class Solution {
    public boolean isValid(String s) {
        char[] sArray = s.toCharArray();
        Stack<Character> charStack = new Stack<>();

        if(sArray.length == 1){
            return false;
        }
        for(int i = 0; i < sArray.length; i++){
            switch (sArray[i]) {
            case '(':
            case '[':
            case '{':
                charStack.push(sArray[i]);
                break;
            case ')':
                if(!charStack.isEmpty() && charStack.pop() == '('){
                    break;
                }else return false;
            case ']':
                if(!charStack.isEmpty() && charStack.pop() == '['){
                    break;
                }else return false;
            case '}':
                if(!charStack.isEmpty() && charStack.pop() == '{'){
                    break;
                }else return false;
            default:
            }
        }

        if(charStack.isEmpty()){
            return true;
        }else{
            return false;
        }
    }
}
