//same leaf nodes or not
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
    void inorder(TreeNode* root, vector<int> &leafNodes){
        if(root==NULL){
            return;
        }
        inorder(root->left, leafNodes);
        if(root->left==NULL && root->right==NULL){
            leafNodes.push_back(root->val);
        }
        inorder(root->right, leafNodes);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>leafNodes1;
        vector<int> leafNodes2;

        inorder(root1, leafNodes1);
        inorder(root2, leafNodes2);
        if(leafNodes1==leafNodes2){
            return true;
        }
        else{
            return false;
        }
    }
};