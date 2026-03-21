/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
    
        if(head==nullptr || head->next==nullptr || (head->next)->next==nullptr){
            return false;
        }
        ListNode* sl=head->next;
        ListNode* fa=sl->next;

        while(sl!=fa){
            if(sl->next==nullptr || fa->next==nullptr || (fa->next)->next==nullptr){
                return false;
            }
            sl=sl->next;
            fa=(fa->next)->next;
        }
        return true;
    }
};