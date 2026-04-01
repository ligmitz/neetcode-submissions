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
        ListNode* summ = new ListNode();
        ListNode* result = summ;
        int temp, carry = 0;
        while (l1 && l2) {
            int temp = (l1->val + l2->val) + carry;
            ListNode* tmpnode = new ListNode(temp % 10);
            summ->next = tmpnode;
            summ = summ->next;
            carry = temp / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1) {
          while (l1) {
            int temp = l1->val + carry;
            ListNode* tmpnode = new ListNode(temp % 10);
            summ->next = tmpnode;
            summ = summ->next;
            carry = temp / 10;
            l1 = l1->next;
          }
        } else if (l2) {
            while (l2) {
                int temp = l2->val + carry;
                ListNode* tmpnode = new ListNode(temp % 10);
                summ->next = tmpnode;
                summ = summ->next;
                carry = temp / 10;
                l2 = l2->next;
            }
        }
        if (carry) {
            ListNode* tmpnode = new ListNode(carry);
            summ->next = tmpnode;
        }

        return result->next;
    }
};
