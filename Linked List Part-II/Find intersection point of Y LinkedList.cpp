/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        while (a != b) {
            a = (a != NULL) ? a->next : headB;
            b = (b != NULL) ? b->next : headA;
        }
        if (a == b) {
            return a;
        }
        return NULL;
    }
};
