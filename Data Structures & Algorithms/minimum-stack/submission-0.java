
class MinStack {
    ArrayList<Integer> stack;
    ArrayList<Integer> minStack;

    public MinStack() {
        stack = new ArrayList<>();
        minStack = new ArrayList<>();
    }
    
    public void push(int val) {
        stack.add(val);
        // Update minStack with the new minimum
        if (minStack.isEmpty() || val <= minStack.get(minStack.size() - 1)) {
            minStack.add(val);
        }
    }
    
    public void pop() {
        if (!stack.isEmpty()) {
            int popped = stack.remove(stack.size() - 1);
            // Update minStack if the popped element was the minimum
            if (popped == minStack.get(minStack.size() - 1)) {
                minStack.remove(minStack.size() - 1);
            }
        }
    }
    
    public int top() {
        return stack.get(stack.size() - 1);
    }
    
    public int getMin() {
        return minStack.get(minStack.size() - 1);
    }
}
