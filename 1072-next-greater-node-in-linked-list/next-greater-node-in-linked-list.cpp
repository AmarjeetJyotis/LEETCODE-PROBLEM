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
   ListNode*rev(ListNode*head)
   {
      if(!head)
      return head;

      ListNode*q=nullptr;
      ListNode*r=nullptr;

      while(head)
      {
        r=q;
        q=head;
        head=head->next;
        q->next=r;
      }

      return q;
   }

    vector<int> nextLargerNodes(ListNode* head) 
    {
       ListNode*newHead=rev(head);
       stack<int>st;
       vector<int>ans;

       while(newHead)
       {
          while(!st.empty() && st.top()<=newHead->val)
          st.pop();

          if(st.empty())
          ans.push_back(0);

          else
          ans.push_back(st.top());

          st.push(newHead->val);
          newHead=newHead->next;
       }

       reverse(ans.begin(),ans.end());

       return ans;
    }
};