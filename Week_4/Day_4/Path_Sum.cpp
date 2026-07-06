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
bool inorder(TreeNode* root,int sum , int &targetSum){
    if(root==NULL){
        return false;
    }
    sum =sum +root->val;
    if(root->left==NULL && root->right==NULL){
        if(targetSum==sum){
            return true;
        }
        return false;
    }
    bool leftside = inorder(root->left , sum , targetSum);
    bool rightside = inorder(root->right , sum , targetSum);
    return leftside || rightside;
}
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum =0;
        bool pathsum = inorder(root,sum,targetSum);
        return pathsum;
    }
};
