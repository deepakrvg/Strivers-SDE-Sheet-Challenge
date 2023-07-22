/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        Node *curr = head;
        while (curr != NULL) {
            Node *temp = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = temp;
            curr = temp;
        }
        curr = head;

        while (curr != NULL) {
            if (curr->next != NULL) {
                curr->next->random = (curr->random != NULL) ? curr->random->next : NULL;
            }
            curr = curr->next->next;
        }

        curr = head;
        Node *l1 = head->next;
        Node *l2 = l1;
        while (curr != NULL) {
            curr->next = curr->next->next;
            if (l1->next == NULL) {
                break;
            }
            l1->next = l1->next->next;
            curr = curr->next;
            l1 = l1->next;
        }
        return l2;
    }
};
