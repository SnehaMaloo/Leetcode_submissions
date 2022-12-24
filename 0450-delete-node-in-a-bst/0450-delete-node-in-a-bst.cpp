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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
        {
            return root;
        }
        if((root->val)==key)
        {
            TreeNode*a=root->left;
            TreeNode*b=root->right;
            if(a!=NULL&&b!=NULL)
            {
                TreeNode*c=b;
                while(c->left!=NULL)
                {
                    c=c->left;
                }
                c->left=a;
                delete(root);
                return b;
            }
            else if(a==NULL)
            {
                return b;
            }
            else return a;
        }
        else if(key<root->val)
        {
            root->left=deleteNode(root->left,key);
        }
        else
        {
            root->right=deleteNode(root->right,key);
        }
        return root;
    }
};