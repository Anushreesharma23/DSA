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
//O(n*n)
class Solution {
public:
int height(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        int ans= max(left, right)+1;
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int op1= diameterOfBinaryTree(root->left);
        int op2= diameterOfBinaryTree(root->right);
        int op3= height(root->left)+height(root->right);
        int ans=max(op1,max(op2,op3));
        return ans;
    }
};
////////////////////////////////////////////////
//O(n);
class Solution {
public:
    pair<bool, int> isBalancedFast(TreeNode* root){
         if(root==NULL){
            pair<bool, int>p = make_pair(true, 0);
            return p;
        }
        pair<int, int> left= isBalancedFast(root->left);
        pair<int, int> right= isBalancedFast(root->right);
        bool leftAns = left.first;
        bool rightAns = right.first;
        bool diff = abs(left.second- right.second)<=1;

        pair<bool, int> ans;
        ans.second = max(left.second, right.second)+1;
        if(leftAns && rightAns && diff){
            ans.first=true;
        }
        else{
            ans.first =false;
        }
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        return (isBalancedFast(root).first);
    }
};