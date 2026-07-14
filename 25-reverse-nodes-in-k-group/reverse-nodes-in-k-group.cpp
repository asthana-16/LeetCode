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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int count=0;
        while(curr && count<k){
            count++;
            curr = curr->next;
        }
        if(count < k) return head;
        count =0;
        curr=head;
        ListNode *next = NULL, *prev=NULL;
        while(count<k){
            next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        head->next= reverseKGroup(curr,k);
        return prev;
    }
};