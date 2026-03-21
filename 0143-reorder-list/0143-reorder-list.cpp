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
        ListNode* t=head;
        int c=0;
        while(t!=nullptr){
            t=t->next;
            c++;
        }
        int k=(c+1)/2-1;
        ListNode* h=head;
        while(k--){
            h=h->next;
        }
        ListNode* tem=h->next;
        stack<int> s;
        while(tem!=nullptr){
            s.push(tem->val);
            tem=tem->next;
        }
        h->next=nullptr;

        ListNode* f=head;
        while(f!=h){
            ListNode* temp=new ListNode(s.top());
            s.pop();
            temp->next=f->next;
            f->next=temp;
            f=temp->next;
        }
        if(s.size()>0){
            ListNode* don=new ListNode(s.top());
            h->next=don;
        }

    }
};