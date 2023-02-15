
// No.94
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


//No.102
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> level1;
        queue<TreeNode*> level2;
        vector<vector<int>> level_list;
        if(root != NULL)
        {
            level1.push(root);
            do{
                vector<int> level1_val;
                TreeNode* current;
                while(! level1.empty()){
                current = level1.front();
                level1.pop();
                if(current->left != NULL)
                    level2.push(current->left);
                if(current->right != NULL)
                    level2.push(current->right);
                level1_val.push_back(current->val);
                }
                level_list.push_back(level1_val);
                level1 = level2;
                level2 = queue<TreeNode*>();
            }while(!level1.empty());    
        }
        return level_list;
    }
};

// No.110
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
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        if(abs(heightoftree(root->left) - heightoftree(root->right)) > 1)
            return false;
        
        if(! isBalanced(root->left))
            return false;
        if(! isBalanced(root->right))
            return false;

        return true;
    }

    int heightoftree(TreeNode* root){
        if(root == NULL)
            return 0;
        int height = 0;
        int height1 = heightoftree(root->left);
        int height2 = heightoftree(root->right);

        if(height1 > height2)
            height = height1;
        else
            height = height2;
            
        return height + 1;
    }
};
