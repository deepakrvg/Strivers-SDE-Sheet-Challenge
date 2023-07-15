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
        ListNode* ptr = headB;
        while (headA != NULL) {
            ptr = headB;
            while (ptr != NULL) {
                if (ptr == headA) {
                    return ptr;
                }
                ptr = ptr->next;
            }
            headA = headA->next;
        }
        return NULL;
    }
};
