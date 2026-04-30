/**
 * Definition for singly-linked listReversed.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode current = head;
        Stack<Integer> stack = new Stack<>();

        while(current != null){
            stack.push(current.val);
            current = current.next;
        }
        // If the stack is empty, return null
        if (stack.isEmpty()) {
            return null;
        }

        ListNode listReversed = new ListNode(stack.pop());
        ListNode currentReversed = listReversed;
        while(!stack.isEmpty()){
            ListNode newNode = new ListNode(stack.pop());
            currentReversed.next = newNode;
            currentReversed = newNode;
        }
        return listReversed;
    }
}
