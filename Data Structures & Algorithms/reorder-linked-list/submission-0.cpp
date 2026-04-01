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
    void reorderList(ListNode* head) {
        vector<ListNode*> part1, part2;
        ListNode *l1 = head, *l2 = head;

        if (!head->next) return;

        while (l2->next && l2->next->next) {
            l2 = l2->next->next;
            l1 = l1->next;
        }
        if (!l2->next) l2 = l1;
        while (l2) {
            part2.push_back(l2);
            l2 = l2->next;
        }
        l1 = head;
        while (l1 != part2[0]) {
            part1.push_back(l1);
            l1 = l1->next;
        }
        reverse(part2.begin(), part2.end());
        int i = 1, j = 0;

        while (i < part1.size()) {
            head->next = part2[j];
            j++;

            head = head->next;
            head->next = part1[i];
            i++;
            head = head->next;
        }
        while (j < part2.size()) {
            head->next = part2[j];
            j++;
            head = head->next;
        }
        head->next = nullptr;
    }
};
