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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> in_map;
        for (int i = 0; i < inorder.size(); ++i)
            in_map[inorder[i]] = i;
        return build(preorder, 0, preorder.size() - 1,
                     inorder, 0, inorder.size() - 1, in_map);
    }

private:
    TreeNode* build(const vector<int>& preorder, int ps, int pe,
                    const vector<int>& inorder, int is, int ie,
                    const unordered_map<int, int>& in_map) {
        if (ps > pe || is > ie) return nullptr;
        int root_val = preorder[ps];
        int k = in_map.at(root_val);
        int left_size = k - is;
        TreeNode* root = new TreeNode(root_val);
        root->left = build(preorder, ps + 1, ps + left_size,
                           inorder, is, k - 1, in_map);
        root->right = build(preorder, ps + left_size + 1, pe,
                            inorder, k + 1, ie, in_map);
        return root;
    }
};
