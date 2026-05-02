#include <stack>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        stack<int> nodeStack;
        ListNode* current = head;
        // check that linked list isn't empty
        if (head == nullptr) return head;

        while (current != nullptr) {
            nodeStack.push(current->val);
            current = current->next;
        }

        ListNode* resHead = new ListNode(nodeStack.top());
        nodeStack.pop();
        ListNode* tail = resHead;

        while (!nodeStack.empty()) {
            int val = nodeStack.top();
            nodeStack.pop();

            ListNode* newNode = new ListNode(val);
            tail->next = newNode;
            tail = newNode;
        }
        return resHead;
    }
};
