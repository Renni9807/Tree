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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> in_map;
        for (int i = 0; i < inorder.size(); ++i)
            in_map[inorder[i]] = i;
        return build(inorder, 0, inorder.size() - 1,
                     postorder, 0, postorder.size() - 1, in_map);
    }

private:
    TreeNode* build(const vector<int>& inorder, int is, int ie,
                    const vector<int>& postorder, int ps, int pe,
                    const unordered_map<int, int>& in_map) {
        if (ps > pe || is > ie) return nullptr;
        int root_val = postorder[pe];
        int k = in_map.at(root_val);
        int left_size = k - is;
        TreeNode* root = new TreeNode(root_val);
        root->left = build(inorder, is, k - 1,
                           postorder, ps, ps + left_size - 1, in_map);
        root->right = build(inorder, k + 1, ie,
                            postorder, ps + left_size, pe - 1, in_map);
        return root;
    }
};