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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = l1;
        ListNode* prev = l1;
        while (l1 != NULL && l2 != NULL) {
            int sum = l1->val + l2->val + carry;
            l1->val = sum % 10;
            carry = sum / 10;
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != NULL) {
            int sum = l1->val + carry;
            l1->val = sum % 10;
            carry = sum / 10;
            prev = l1;
            l1 = l1->next;
        }
        while (l2 != NULL) {
            int sum = l2->val + carry;
            ListNode* new_node = new ListNode(sum % 10);
            prev->next = new_node;
            prev = prev->next;
            carry = sum / 10;
            l2 = l2->next;
        }
        if (carry) {
            ListNode* new_node = new ListNode(carry);
            prev->next = new_node;
        }
        return head;
    }
};
