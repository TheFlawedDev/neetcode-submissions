/**
 * Definition for singly-linked list.
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
        // Handle edge cases: empty list or single-node list
        if (head == null || head.next == null) {
            return head;
        }

        Stack<Integer> myStack = new Stack<>();
        ListNode current = head;

        // Step 1: Push all node values onto the stack
        while (current != null) {
            myStack.push(current.val);
            current = current.next;
        }

        // Step 2: Create a new linked list from the stack
        // The first element popped will be the new head
        ListNode newHead = new ListNode(myStack.pop());
        ListNode temp = newHead; // Use a temporary pointer to build the list

        while (!myStack.isEmpty()) {
            temp.next = new ListNode(myStack.pop()); // Create a new node for each popped element
            temp = temp.next; // Move the temporary pointer to the newly created node
        }

        return newHead;
    }
}
