class Solution {
    public int evalRPN(String[] tokens) {
    Deque<Integer> stack = new ArrayDeque<>();
        
        for (String token : tokens) {
            // If token is a number, push to stack
            if (token.matches("-?\\d+")) {   
                stack.push(Integer.parseInt(token));
                continue;
            }
            
            // If token is an operator, pop two numbers and perform operation
            int num2 = stack.pop();
            int num1 = stack.pop();
            
            int result;
            switch (token) {
                case "+":
                    result = num1 + num2;
                    break;
                case "-":
                    result = num1 - num2;
                    break;
                case "*":
                    result = num1 * num2;
                    break;
                case "/":
                    result = num1 / num2;
                    break;
                default:
                    throw new IllegalArgumentException("Invalid operator: " + token);
            }
            stack.push(result);
        }
        
        return stack.pop(); 
    }
}
