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
        ListNode* head=new ListNode(0);
        ListNode* l=head;
        while(list1!=nullptr || list2!=nullptr){
            int n=0;
            int a=101,b=101;
            if(list1!=nullptr){  a=list1->val;}
            if(list2!=nullptr){  b=list2->val;}
            if(a<b) list1=list1->next;
            else    list2=list2->next;
            n=min(a,b);
            l->next=new ListNode(n);
            l=l->next;
        
        }
        return head->next;
    }
};