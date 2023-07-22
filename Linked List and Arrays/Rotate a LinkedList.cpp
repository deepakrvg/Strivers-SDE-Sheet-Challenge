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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        int len = 0;
        while (slow != NULL) {
            len++;
            slow = slow->next;
        }
        k = k % len;
        if (k == 0) {
            return head;
        }
        slow = head;
        while (k) {
            fast = fast->next;
            k--;
        }
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *temp = slow->next;
        slow->next = NULL;
        fast->next = head;
        return temp;
    }
};
