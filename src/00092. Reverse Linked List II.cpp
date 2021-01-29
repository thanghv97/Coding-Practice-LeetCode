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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        head = new ListNode(0, head);
        ListNode* prev = head;
        ListNode** pp = &(head->next);
        ListNode *ite, *ite_n, *ite_m;
        int cs = 0;
        
        while ((ite = *pp)) {
            if (++cs == m) {
                ite_n = ite;
                ite_m = ite;
                ite = ite->next;
                while (++cs <= n) {
                    ListNode *nxt = ite->next;
                    ite->next = ite_m;
                    ite_m = ite;
                    ite = nxt;
                }
                ite_n->next = ite;
                prev->next = ite_m;  
                ite = ite_n;
            }
            prev = ite;
            pp = &(ite->next);
        }
        return head->next;
    }
};