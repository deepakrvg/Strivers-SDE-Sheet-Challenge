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
        if (head == NULL) {
            return head;
        }
        ListNode* nxt = head->next;
        ListNode* curr = head;
        curr->next = NULL;
        while (nxt != NULL) {
            head = nxt;
            nxt = nxt->next;
            head->next = curr;
            curr = head;
        }
    return curr;
    }
};
