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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;
        for(auto& a:lists){
            ListNode* head=a;
            while(head!=nullptr){
                v.push_back(head->val);
                head=head->next;
            }
        }
        sort(v.begin(),v.end());
        ListNode* head=new ListNode(0);
        ListNode* l=head;
        for(int i:v){
            ListNode* t=new ListNode(i);
            l->next=t;
            l=l->next;
        }
        return head->next;
    }
};