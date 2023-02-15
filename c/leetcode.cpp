
# No.94
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> val_list;
        traveler(root, val_list);
        return val_list;
    }

    void traveler(TreeNode* root, vector<int>& val_list){
        if(root != NULL){
            traveler(root->left, val_list);
            val_list.push_back(root->val);
            traveler(root->right, val_list);
        }
        
    }
};
