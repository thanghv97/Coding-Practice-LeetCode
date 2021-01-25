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
        ListNode** pp = &head;
        ListNode* a;
        
        while ((a = *pp)) {
            while (a->next != nullptr && a->val == a->next->val) {
                a->next = a->next->next;
            }
            pp = &(a->next);
        }
        return head;
    }
};