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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return identical(p, q);
    }

    bool identical(TreeNode* p, TreeNode* q)  {

        if(p==nullptr&&q==nullptr) return true;
        if(p==nullptr||q==nullptr) return false;

        return (p->val==q->val) && identical(p->left, q->left) && identical(p->right, q->right);
    }
};