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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) {
            return list2;
        }
        if (list2 == NULL) {
            return list1;
        }
        ListNode* i = list1;
        ListNode* j = list2;
        ListNode* prev = NULL;
        if (i->val <= j->val) {
            prev = i;
            i = i->next;
        }
        else {
            prev = j;
            j = j->next;
        }
        while (i != NULL && j != NULL) {
            if (i->val <= j->val) {
                prev->next = i;
                prev = i;
                i = i->next;
            }
            else {
                prev->next = j;
                prev = j;
                j = j->next;
            }
            // prev->next = NULL;
        }
        if (i != NULL) {
            prev->next = i;
        }
        if (j != NULL) {
            prev->next = j;
        }
        return (list1->val <= list2->val) ? list1 : list2;
    }
};
