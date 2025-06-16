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

    ListNode* reverse(ListNode* &head){
        if(head==NULL){
            return head;
        }
        // one case for ll
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr != NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL){
            return true;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
            //find the middle term
            ListNode* reverseLLkaHead=reverse(slow);
        
        ListNode* temp1=head;
        ListNode* temp2=reverseLLkaHead;
        while(temp2 !=NULL){
            if(temp1->val != temp2->val){
                return false;
            }
            else{
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }
        return true;
    }
};