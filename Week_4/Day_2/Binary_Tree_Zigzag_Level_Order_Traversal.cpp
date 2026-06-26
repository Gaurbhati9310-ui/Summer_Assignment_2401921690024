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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        bool lefttoright = true;
        if(root==NULL){
            return {};
        }
        vector<vector<int>>result;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>level(size);
          for(int i=0;i<size;i++){
            TreeNode *temp = q.front();
            q.pop();
            // decide index 
            int index = lefttoright? i: size-i-1;
            level[index] = temp->val;
            if(temp->left){
                q.push(temp->left);
            }
             if(temp->right){
              
          q.push(temp->right);
            }
          }
            result.push_back(level);

          
          //toggle 
          lefttoright=!lefttoright;
        
        
        }
        return result;
    }
};
