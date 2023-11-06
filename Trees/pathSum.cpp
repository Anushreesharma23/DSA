// https://leetcode.com/problems/path-sum/submissions/1091186750/
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
private:
    bool Sum(TreeNode* root, int target, int temp){
        if(root==NULL){
            return false;
        }
        if(root->right==NULL && root->left==NULL){
            if(target==temp + root->val){
                return true;
            }
            else{
                return false;
            }
        }
        bool left = Sum(root->left, target, temp+root->val);
        bool right = Sum(root->right, target, temp+root->val);
        return left || right;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        int temp =0;
        return Sum(root,targetSum, temp);
    }
};