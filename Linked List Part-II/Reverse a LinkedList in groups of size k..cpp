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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) {
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = dummy;
        ListNode* prev = dummy;
        ListNode* nxt = dummy;

        int len = 0;
        while (curr->next != NULL) {
            len++;
            curr = curr->next;
        }

        while (len >= k) {
            curr = prev->next;
            nxt = curr->next;
            for (int i = 0; i < k - 1; i++) {
                curr->next = nxt->next;
                nxt->next = prev->next;
                prev->next = nxt;
                nxt = curr->next;
            }
            prev = curr;
            len -= k;
        }
        return dummy->next;
    }
};
