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
        Node *l1 = NULL;
        Node *l2 = head;
        Node *temp;
        int len = 0;
        while (l2 != NULL) {
            if (l1 == NULL) {
                l1 = new Node(l2->val);
                temp = l1;
            }
            else {
                Node *new_node = new Node(l2->val);
                temp->next = new_node;
                temp = new_node;
            }
            l2 = l2->next;
            len++;
        }

        int arr[len];
        memset(arr, 0, sizeof(arr));
        l2 = head;
        Node* l3 = head;
        int index = 0;
        int k = 0;
        while (l2 != NULL) {
            l3 = head;
            Node *temp = l2->random;
            index = 0;
            while (l3 != temp) {
                l3 = l3->next;
                index++;
            }
            arr[k] = index;
            l2 = l2->next;
            k++;
        }

        l2 = l1;
        l3 = l1;
        k = 0;
        while (l2 != NULL) {
            l3 = l1;
            if (arr[k] == len) {
                k++;
                l2->random = NULL;
                l2 = l2->next;
                continue;
            }
            while (arr[k]) {
                l3 = l3->next;
                arr[k]--;
            }
            k++;
            l2->random = l3;
            l2 = l2->next;
        }

        return l1;
    }
};
