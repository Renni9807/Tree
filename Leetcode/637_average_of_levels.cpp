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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<long long> sums;
        vector<int> counts;
        
        dfs(root, 0, sums, counts);
        
        vector<double> result;
        for (int i = 0; i < sums.size(); i++) {
            result.push_back((double)sums[i] / counts[i]);
        }
        
        return result;
    }
    
private:
    void dfs(TreeNode* node, int level, vector<long long>& sums, vector<int>& counts) {
        if (!node) return;
        
        if (level >= sums.size()) {
            sums.push_back(0);
            counts.push_back(0);
        }
        
        sums[level] += node->val;
        counts[level]++;
        
        dfs(node->left, level + 1, sums, counts);
        dfs(node->right, level + 1, sums, counts);
    }
};