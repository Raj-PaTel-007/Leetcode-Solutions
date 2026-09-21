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
        if(!head) return head;
        ListNode*temp1 = NULL;
        ListNode*temp2 = NULL;
        ListNode*head1 = NULL;
        ListNode* head2 = NULL;
        ListNode*temp = head;
        while(temp){
            if(temp->val < x) {
                if(!temp1){
                    temp1 = temp;
                    head1 = temp;
                }
                else{
                    temp1 -> next = temp;
                    temp1 = temp1 -> next;
                }
            }
            else{
                if(!temp2){
                    temp2 = temp;
                    head2 = temp;
                }
                else{
                    temp2 -> next = temp;
                    temp2 = temp2 -> next;
                }
            }
            temp = temp->next;
        }
    if(!head1) {
            temp2->next = NULL;
            return head2;
        }

        if(temp2)
            temp2->next = NULL;

        temp1->next = head2;
        return head1;
    }
};