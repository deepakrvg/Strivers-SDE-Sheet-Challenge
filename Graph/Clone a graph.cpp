/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node *node, Node *copy, vector<Node*> &vis) {
        vis[copy->val] = copy;
        for (auto x : node->neighbors) {
            if (vis[x->val] == NULL) {
                Node *new_node = new Node(x->val);
                (copy->neighbors).push_back(new_node);
                dfs(x, new_node, vis);
            }
            else {
                (copy->neighbors).push_back(vis[x->val]);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return NULL;
        }
        Node *copy = new Node(node->val);
        vector<Node*> vis(105, NULL);
        dfs(node, copy, vis);
        return copy;
    }
};
