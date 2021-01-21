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
    ListNode* deleteDuplicates(ListNode* head) {
        head = new ListNode(0, head);
        ListNode *a, **pp = &(head), *b = *pp;
        pp = &((*pp)->next);
        
        while ((a = *pp)) {
            bool check = false;
            while (a->next != nullptr && a->next->val == a->val) {
                check = true;
                a->next = a->next->next;
            }
            
            if (!check) {
                b = *pp;
                pp = &((*pp)->next);
            } else {
                b->next = a->next;
            }
        }
        return head->next;
    }
};