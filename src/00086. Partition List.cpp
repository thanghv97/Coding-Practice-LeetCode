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
    ListNode* partition(ListNode* head, int x) {
        head = new ListNode(-201, head);
        ListNode **pp = &head;
        ListNode *ite;
        ListNode *par_less = nullptr, *par_greater = nullptr;
        
        while ((ite = *pp)->next) {
            if (ite->next->val >= x) {
                if (par_greater == nullptr) {
                    par_greater = ite->next;
                }
                ite = ite->next;
            } else {
                if (par_less == nullptr) {
                    par_less = ite->next;
                    head = par_less;
                } else {
                    par_less->next = ite->next;
                    par_less = par_less->next;
                }
                ite->next = ite->next->next;
            }
            pp = &(ite);
        }
        
        if (!par_less) {
            return par_greater;
        } else {
            par_less->next = par_greater;
        }
        return head;
    }
};