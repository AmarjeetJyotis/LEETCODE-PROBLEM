/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int maxLevelSum(TreeNode* root) {
        
        if(!root)return 0;
        queue<TreeNode*>q;
        int ans=1;
        q.push(root);
        int level=0;
        int maxsum=INT_MIN;
        while(!q.empty())
        {
            level++;
            int n=q.size();
            int sum=0;
            while(n>0)
            {
                auto it=q.front();
                q.pop();
               sum+=it->val;
               if(it->left)q.push(it->left);
               if(it->right)q.push(it->right);
               n--;
            }
            if(sum>maxsum)
            {
            maxsum=sum;
            ans=level;
            }
        }
        return ans;
    }
};