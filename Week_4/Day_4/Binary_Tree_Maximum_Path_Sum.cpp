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
   
   int maxsum;
   int solve(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int left = solve(root->left);
    int right = solve(root->right);
    int neche_hi_mil_gya_answer = left+right + root->val; // 1
    int koi_ek_acha = max(left,right)+ root->val;
    int root_hi_acha = root->val;
     maxsum = max({maxsum , neche_hi_mil_gya_answer , koi_ek_acha , root_hi_acha} );
    return max(koi_ek_acha,root_hi_acha);
   }
    int maxPathSum(TreeNode* root) {
        maxsum = INT_MIN;
        solve(root);
        return maxsum;
    }
};
