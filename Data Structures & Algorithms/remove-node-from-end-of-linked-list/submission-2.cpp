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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *pointer1 = head, *pointer2 = head;
        while (n--) {
            pointer2 = pointer2->next;
        }
        if (!pointer2) return pointer1->next; 
        while (pointer2 && pointer2->next) {
            pointer1 = pointer1->next;
            pointer2 = pointer2->next;
        }
        ListNode* removed = pointer1->next;
        if (!removed) return nullptr;
        if (removed->next) pointer1->next = removed->next;
        else pointer1->next = nullptr;
        return head;
    }
};
