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
        ListNode* listr = new ListNode();
        ListNode* head = listr;

        while (list1 != nullptr && list2 !=nullptr) {
            if (list1->val < list2->val) {
                ListNode* node = new ListNode(list1->val);
                listr->next = node;
                list1 = list1->next;
            } else {
                ListNode* node = new ListNode(list2->val);
                listr->next = node;
                list2 = list2->next;
            }
            listr = listr->next;
        }
        while (list1 != nullptr) {
            ListNode* node = new ListNode(list1->val);
            listr->next = node;
            listr = listr->next;
            list1 = list1->next;
        }
        while (list2 != nullptr) {
            ListNode* node = new ListNode(list2->val);
            listr->next = node;
            listr = listr->next;
            list2 = list2->next;
        }

        return head->next;
    }
};
