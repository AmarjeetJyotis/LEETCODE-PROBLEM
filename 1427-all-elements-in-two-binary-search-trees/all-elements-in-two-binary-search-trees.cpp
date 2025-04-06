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
    void inorder(vector<int>&arr,TreeNode* root){
        if(!root) return;
        inorder(arr,root->left);
        arr.emplace_back(root->val);
        inorder(arr,root->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>list1,list2;
        inorder(list1,root1);
        inorder(list2,root2);
        vector<int>sol;
        int i=0;
        int j=0;
        while(i<list1.size() && j<list2.size()){
            if(list1[i]>list2[j]) sol.emplace_back(list2[j++]);
            else sol.emplace_back(list1[i++]);
    }
    while(i<list1.size()){
        sol.emplace_back(list1[i++]);
    }
    while(j<list2.size()){
        sol.emplace_back(list2[j++]);
    }
        return sol;
    }
};