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
        vector<ListNode*> a;
        
        ListNode* p = head;
        while (p != nullptr) {
            a.push_back(p);
            p = p->next;
        }
        if (a.size() - n == 0) {
            head = head->next;
        } else {
            a[a.size()-n-1]->next = a[a.size()-n]->next;
        }
        
        return head;
    }
};