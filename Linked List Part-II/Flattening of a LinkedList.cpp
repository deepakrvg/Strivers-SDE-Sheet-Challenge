/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

Node* mergeLL(Node* l1, Node* l2) {
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }
    
    Node* list1 = l1;
    Node *list2 = l2;
    Node* curr;
    if (l1->data <= l2->data) {
        curr = l1;
        l1 = l1->bottom;
    }
    else {
        curr = l2;
        l2 = l2->bottom;
    }
    
    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            curr->bottom = l1;
            curr = l1;
            l1 = l1->bottom;
        }
        else {
            curr->bottom = l2;
            curr = l2;
            l2 = l2->bottom;
        }
    }
    if (l1 != NULL) {
        curr->bottom = l1;
    }
    if (l2 != NULL) {
        curr->bottom = l2;
    }
    return (list1->data <= list2->data) ? list1 : list2;
}

/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
   // Your code here
   if (root->next == NULL) {
       return root;
   }
   Node* temp = flatten(root->next);
   Node* head = mergeLL(root, temp);
   return head;
}
