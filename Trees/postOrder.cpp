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
void ans(TreeNode* root, vector<int>& Result){
    if(root==NULL){
        return;
    }
    ans(root->left, Result);
    ans(root->right, Result);
    Result.push_back(root->val);
}
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> Result;
        ans(root, Result);
        return Result;
    }
};