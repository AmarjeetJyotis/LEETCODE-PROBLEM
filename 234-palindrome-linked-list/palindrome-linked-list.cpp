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
        if(head == NULL){
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return true;
        }

        // Step 1: Find the middle node
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half
        ListNode* reverseLLkaHead = reverse(slow);

        // Step 3: Compare both halves
        ListNode* temp1 = head;
        ListNode* temp2 = reverseLLkaHead;
        while(temp2 != NULL){
            if(temp1->val != temp2->val){
                return false;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return true;
    }
};
