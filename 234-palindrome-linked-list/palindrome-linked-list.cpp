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
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head, *fast=head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *next = NULL, *prev = NULL, *curr = slow->next;
        while(curr){
            next = curr->next;
            curr->next=prev;
            prev=curr;
            curr = next;
        }
        ListNode* left = head;
        ListNode* right = prev;
        while(right){
            if(left->val != right->val)return false;
            right = right->next;
            left = left->next;

        }
        return true;
    }
};