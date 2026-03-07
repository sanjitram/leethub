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
        ListNode* l3=new ListNode();
        ListNode* ln3=l3;
        int c=0;
        while(l1!=nullptr || l2!=nullptr){
            int s=c;
            if(l1!=nullptr){
                s+=(l1->val);
                l1=l1->next;
            }
            if(l2!=nullptr){
                s+=(l2->val);
                l2=l2->next;
            }
            ListNode* l=new ListNode(s%10);
            ln3->next=l;
            ln3=l;
            c=s/10;
        
        }
        if(c!=0){
            ln3->next=new ListNode(c);
        }

        ListNode* ans=l3->next;
        return ans;
    }
};