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
        unordered_map<Node*, Node*> mappings;
        if (!head) return nullptr;
        Node *newpointer = new Node(head->val);
        mappings[head] = newpointer;
        Node *pointer = head, *newhead = newpointer;
        while (pointer->next) {
            newpointer->next = new Node(pointer->next->val);
            newpointer = newpointer->next;
            mappings[pointer->next] = newpointer;
            pointer = pointer->next;
        }
        pointer = head; newpointer = newhead;
        while (pointer) {
            if (mappings.find(pointer->random) != mappings.end()) newpointer->random = mappings[pointer->random];
            pointer = pointer->next;
            newpointer = newpointer->next;
        }
        return newhead;
    }
};
