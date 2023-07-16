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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* curr = slow->next;
        ListNode* prev = NULL;
        ListNode* nxt = curr->next;
        while (curr != NULL) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        slow->next = prev;

        fast = head;
        while (fast != NULL) {
            cout << fast->val << " ";
            fast = fast->next;
        }

        slow = slow->next;
        // cout << slow->val;
        while (slow != NULL) {
            if (head->val != slow->val) {
                return false;
            }
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
};
