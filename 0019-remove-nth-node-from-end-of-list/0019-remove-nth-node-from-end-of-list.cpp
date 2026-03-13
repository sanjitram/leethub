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
        ListNode* l=head;
        int c=0;
        while(l!=nullptr){
            l=l->next;
            c++;
        }
        int p=(c-n-1);
        if(p==-1)
            return head->next;
        ListNode* m=head;
        while(p--){
            m=m->next;
        }
        ListNode* r=m->next;
        m->next=r->next;
        delete r;
        return head;
    }
};