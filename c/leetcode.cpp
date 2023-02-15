// No.54
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> spiral;
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        int j = 0;
        int up = 0;
        int left = 0;
        int down = m - 1;
        int right = n - 1;
        int length = m * n;

        while(up <= down || left <= right ){
        if(spiral.size() >= length)
            break;
            
        for(j = left; j <= right; j++)
            spiral.push_back(matrix[up][j]);
        up++;

        if(spiral.size() >= length)
            break;

        for(i = up; i <= down; i++)
            spiral.push_back(matrix[i][right]);
        right--;

        if(spiral.size() >= length)
            break;

        for(j = right; j >= left; j--)
            spiral.push_back(matrix[down][j]);
        down--;

        if(spiral.size() >= length)
            break;

        for(i = down; i >= up; i--)
            spiral.push_back(matrix[i][left]);
        left++;

        }
        
        return spiral;
    }
};

// No.73
// space O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        bool firstr = false;
        bool firstc = false;
        for(int j = 0; j < n; j++)
        {
            if(matrix[0][j]==0)
            {
                firstr = true;
                break;
            }   
        }
        for(int i = 0; i < m; i++)
        {
            if(matrix[i][0]==0)
            {
                firstc = true;
                break;
            }
        }

        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(matrix[0][j]==0 || matrix[i][0]==0)
                    matrix[i][j] = 0;
            }
        }

        if(firstr)
        {
            for(int j = 0; j < n; j++)
                matrix[0][j] = 0;
        }
        if(firstc)
        {
            for(int i = 0; i < m; i++)
                matrix[i][0] = 0;
        }
    }
};

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
