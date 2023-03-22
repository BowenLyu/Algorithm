// 03
// time O(n) space O(n)
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        int a[n];
        memset(a, 0, sizeof(a));

        for(int i = 0; i < n; i++){
            if(a[nums[i]])
                return nums[i];
            a[nums[i]]++;
        }
        return -1;
    }
};

//time O(n) space O(1)
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i < n){
            if(nums[i] == i)
                i++;
            else if(nums[i] == nums[nums[i]])
                return nums[i];
            else{
                int temp = nums[nums[i]];
                nums[nums[i]] = nums[i];
                nums[i] = temp;
            }
        }
        return -1;
    }
};

// 04
// 最初的想法类似，但是还是有问题。1.陷入了几个特殊情况的错误中。 2.通过中间点只可瞬间确定x在某一个区域，但好像还是很不方便。以及下面的代码仍有错。
// class Solution {
// public:
//     bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
//         if(matrix.size() == 0)
//             return false;
//         if(matrix[0].size() == 0)
//             return false;
//         int u = 0;
//         int d = matrix.size() - 1;
//         int l = 0;
//         int r = matrix[0].size() - 1;

//         while(d - u > 1 && r - l > 1){
//             int midr = (u + d)/2;
//             int midc = (l + r)/2;
//             if(matrix[midr][midc] == target)
//                     return true;
//             else if(matrix[midr][midc] < target){
//                 u = midr;
//                 l = midc;
//             }
//             else{
//                 d = midr;
//                 r = midc;
//             }
//         }

//         if(matrix[u][l] == target)
//             return true;
        
//         int ptl = 0;
//         int ptr = r;
//         while(ptl <= ptr){
//             int mid = (ptl + ptr) >> 1;
//             if(matrix[d][mid] == target)
//                 return true;
//             else if(matrix[d][mid] < target)
//                 ptl = mid + 1;
//             else
//                 ptr = mid - 1;
//         }

//         int ptu = 0;
//         int ptd = d;
//         while(ptu <= ptd){
//             int mid = (ptu + ptd) >> 1;
//             if(matrix[mid][r] == target)
//                 return true;
//             else if(matrix[mid][r] < target)
//                 ptu = mid + 1;
//             else
//                 ptd = mid - 1;
//         }

//         return false;
//     }
// };

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0)
            return false;
        if(matrix[0].size() == 0)
            return false;

        int r = 0;
        int c = matrix[0].size() -1;

        while(r < matrix.size() && c >= 0){
            if(target == matrix[r][c])
                return true;
            else if(target < matrix[r][c])
                c--;
            else
                r++;
        }
        return false;
    }
};

// 05
// 得找个时间系统的看一下关于字符串的内容
class Solution {
public:
    string replaceSpace(string s) {
        int n = s.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            if(s[i + count * 2] == ' '){
                s.replace(i + count * 2, 1, "%20", 0, 3);
                count++;
            }   
        }
        return s;
    }
};

// 06
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {

        vector<int> output;
        reverse(head, output);
        return output;
    }

    void reverse(ListNode* head, vector<int>& nums){
        if(head == NULL)
            return;

        reverse(head->next, nums);
        nums.push_back(head->val);
    }
};

// 09
class CQueue {
public:
    stack<int> q1;
    stack<int> q2;

    CQueue() {
    }
    
    void appendTail(int value) {
        q1.push(value);
    }
    
    int deleteHead() {
        if(q2.empty()){
            if(q1.empty())
                return -1;
            else{
                while(! q1.empty()){
                    q2.push(q1.top());
                    q1.pop();
                }
            }
        }
        int output = q2.top();
        q2.pop();
        return output;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

// 10
class Solution {
public:
    int fib(int n) {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        
        int MOD = 1000000007;

        int a0 = 0,  a1 = 1;
        int a2 = 0 + 1;
        // a0 a1 a2
        //    a0 a1 a2
        for(int i = 2; i < n; i++){
            a0 = a1;
            a1 = a2;
            a2 = (a0 + a1) % MOD;
        } 
        return a2;
    }
};

// 10-2
class Solution {
public:
    int numWays(int n) {
        if(n == 0)
            return 1;
        if(n == 1)
            return 1;

        int MOD = 1000000007;
        int a0 = 1, a1 = 1, a2 = 2;
        for(int i = 2; i < n; i++){
            a0 = a1;
            a1 = a2;
            a2 = (a0 + a1) % MOD;
        } 
        return a2;
    }
};

//11
//需要重点温习的题目
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int l = 0;
        int r = numbers.size() -1;
        int mid;
        while(l < r){
            mid = (l + r)/2;
            if(numbers[mid] < numbers[r])
                r = mid;
            else if(numbers[mid] > numbers[r])
                l = mid + 1;
            else
                r--;
        }       
        return numbers[r];
    }
};

// 12
// 回溯和DFS 需要重点温习熟练
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j]==word[0]){
                    bool ans = check(board, word, i, j, 0);
                    if(ans)
                        return ans;
                }
            }
        }
        return false;
    }

    bool check(vector<vector<char>>& board, string word, int i, int j, int k){
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return false;

        if(board[i][j] == '\0')
            return false;

        if(board[i][j] == word[k]){
            if(k == word.size() -1)
                return true;
            board[i][j] = '\0';
            bool c1 = check(board, word, i-1, j, k+1);
            bool c2 = check(board, word, i+1, j, k+1);
            bool c3 = check(board, word, i, j-1, k+1);
            bool c4 = check(board, word, i, j+1, k+1);

            board[i][j] = word[k];
            if(c1 || c2 || c3 || c4)
                return true;
        }
        
        return false;
         
    }
};

//14-1
//动态规划非递归写法
class Solution {
public:
    int cuttingRope(int n) {
        if(n < 3)
            return 1;
        int l[n]; 
        memset(l, 0, sizeof(int) * n);
        l[0] = 0;
        l[1] = 1;
        int l1, l2;
        for(int i = 2; i < n; i++){
            for(int j = 1; j <= i/2; j++){
                if(l[j] < j+1)
                    l1 = j+1;
                else
                    l1 = l[j];
                
                if(l[i-j-1] < i-j)
                    l2 = i-j;
                else
                    l2 = l[i-j-1];

                if(l[i] < l1 * l2)
                    l[i] = l1 * l2;
            }
        }

        return l[n-1];
    }

};

// 14-2
// 目前只会用贪心去处理边界问题， 动态规划模完不好比较大小
class Solution {
public:
    int cuttingRope(int n) {
        if(n < 4)
            return n-1;
        int MOD = 1000000007;
        long max = 1;
        while(n > 4){
            n -=3;
            max = (max * 3) % MOD;
        }
        return (max * n) % MOD;
        
    }
};

// 15
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for(int i = 0; i < 32; i++){
            if(n & 1)
                count++;
            n >>= 1;
        }
        return count;
    }
};

// 16
// 快速pow还蛮常见的
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        return N>=0 ? quickpow(x, N) : 1.0 / quickpow(x, -N);
    }

    double quickpow(double x, long long N){
        double ans = 1;
        double cur = x;
        while(N > 0){
            if(N % 2 == 1)
                ans *= cur;

            cur *= cur;
            N /= 2;
        }
        return ans;
    }
};

// 17
// 看评论原题应该是要用大数，所以考察的是字符串表达，晚点再写一个版本的
class Solution {
public:
    vector<int> printNumbers(int n) {
        int border = pow(10, n);
        vector<int> output;
        for(int i = 1; i < border; i++){
            output.push_back(i);
        }
        return output;
    }
};

// 18
// 简单的链表题，注意不出错吧
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head == NULL)
            return NULL;

        if(head->val == val)
            return head->next;

        ListNode* cur = head;

        while(cur->next != NULL && cur->next->val != val)
            cur = cur->next;

        if(cur->next != NULL)
            cur->next = cur->next->next;

        return head;
    }
};


// 19
// 这题是真的难，转移方程情况挺绕的，经常拿出来瞅瞅吧
class Solution {
public:
    bool isMatch(string s, string p) {
        int ns = s.size();
        int np = p.size();

        int f[ns + 1][np + 1];
        memset(f, 0, sizeof(int) * (ns+1)*(np+1));
        f[0][0] = 1;

        for(int j = 2; j < np + 1; j+=2){
            if(f[0][j-2] && p[j-1]=='*')
                f[0][j] = 1;
        }


        for(int i = 1; i < ns + 1; i++){
            for(int j = 1; j < np + 1; j++){
                if(p[j-1] != '*'){
                    if(p[j-1] == '.')
                        f[i][j] = f[i-1][j-1];
                    else{
                        if(p[j-1] == s[i-1] && f[i-1][j-1])
                            f[i][j] = 1;
                    }
                }
                else{
                    if(p[j-2] == '.'){
                        if(f[i-1][j] || f[i][j-2])
                            f[i][j] = 1;
                    }
                    else if(p[j-2] == s[i-1]){
                        if(f[i-1][j] || f[i][j-2])
                            f[i][j] = 1;
                    }
                    else{
                        f[i][j] = f[i][j-2];
                    }
                }
            }
        }

        if(f[ns][np] == 1)
            return true;
        else
            return false;
    }
};

// 21
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        while(l < r){
            while(nums[l] %2 == 1 && l < r) //这个地方是否 l<r放前面会好一些？
                l++;
            while(nums[r] %2 == 0 && l < r)
                r--;

            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
        }
        return nums;
    }
};

// 22
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* first = head;
        ListNode* second = head;
        while(k>0){
            first = first->next;
            k--;
        }
        while(first){
            first = first->next;
            second = second->next;
        }
        return second;
    }
};

// 24 
// 不是很熟，需要多看一下，主要是利用了一个空指针，避免了“环”的产生
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* first = head;
        ListNode* second = nullptr;

        while(first){
            ListNode* temp = second;
            second = first;
            first = first->next;
            second->next = temp;
        }
        return second;
    }
};

// 25
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while(l1 && l2){
            if(l1->val > l2->val){
                cur->next = l2;
                l2 = l2->next;
            }
            else{
                cur->next = l1;
                l1 = l1->next;
            }
            cur = cur->next;
        }
        if(l1)
            cur->next = l1;
        if(l2)
            cur->next = l2;

        return dummy->next;
    }
};

// 26 
// 分类错了很多次
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(B == NULL)
            return false;
        return check(A,B,0);
    }

    bool check(TreeNode* A, TreeNode* B, int start){
        if(B==NULL)
            return true;

        bool same1 = false, same2 = false;
        if(A && B){
            if(A->val == B->val)
                same1 = check(A->left,B->left, start + 1) && check(A->right, B->right, start + 1);
            else if(start)
                return false;
            if(start == 0)
                same2 = check(A->left, B, start) || check(A->right, B, start);
            
        }
        return same1 || same2;
    }
};

// 27
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == NULL || (root->left == NULL && root->right == NULL))
            return root;
        TreeNode* temp = mirrorTree(root->left);
        root->left = mirrorTree(root->right);
        root->right = temp;
        
        return root;
    }
};

// 28
// 稍微有点绕的递归，主要是如何两边同时做dfs
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return isSymmetricSub(root->left, root->right);
    }

    bool isSymmetricSub(TreeNode* left, TreeNode* right) {
        if(!left && !right)
            return true;
        
        if(!left || !right || left->val != right->val)
            return false;

        return isSymmetricSub(left->left, right->right) && isSymmetricSub(left->right, right->left);
    }

};

// 29
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(!matrix.size())
            return {};

        int top = 0;
        int bottle = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        vector<int> output;
        int flag = 0;

        while(top <= bottle && left <= right) {
            if(flag == 0) {
                for(int j = left; j <= right; j++)
                    output.push_back(matrix[top][j]);
                top++;
                flag = 1;
                continue;
            }
            if(flag == 1) {
                for(int i = top; i <= bottle; i++)
                    output.push_back(matrix[i][right]);
                right--;
                flag = 2;
                continue;
            }
            if(flag == 2) {
                for(int j = right; j >= left; j--)
                    output.push_back(matrix[bottle][j]);
                bottle--;
                flag = 3;
                continue;
            }
            if(flag == 3) {
                for(int i = bottle; i >= top; i--)
                    output.push_back(matrix[i][left]);
                left++;
                flag = 0;
                continue;
            }
        }
        return output;
    }
};

// 30 
// 最小栈数据结构，不是很熟，不难需要回顾一下
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    stack<int> mins;

    MinStack() {
        mins.push(INT_MAX);
    }
    
    void push(int x) {
        s.push(x);
        if(mins.top() >= x)
            mins.push(x);
        else
            mins.push(mins.top());
    }
    
    void pop() {
        s.pop();
        mins.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int min() {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */

// 31
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int n = pushed.size();
        int j = 0;
        for(int i = 0; i < n; i++) {
            s.push(pushed[i]);
            while(! s.empty() && s.top() == popped[j]) {
                s.pop();
                j++;
            }
        }

        return s.empty();
    }
};

// 32
// 最开始想用DFS写，但是需要注意怎么处理这个动态向量
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<vector<int>> output;
        wfs(root, output, 0);
        vector<int> ans;
    }

    void wfs(TreeNode* root, vector<vector<int>>& output, int depth) {
        if(!root)
            return;
        output[depth].push_back(root->val);
        wfs(root->left, output, depth+1);
        wfs(root->right, output, depth+1);
    }
};

// BFS 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        if(!root)
            return {};

        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(! q.empty()) {
            ans.push_back(q.front()->val);
            if(q.front()->left)
                q.push(q.front()->left);
            if(q.front()->right)
                q.push(q.front()->right);
            q.pop();
        }
        return ans;
    }

};

// 32-2
// DFS 实现
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root, ans, 0);
        return ans;
    }

    void dfs(TreeNode* root, vector<vector<int>>& output, int depth) {
        if(! root)
            return;
        if(output.size() <= depth)
            output.emplace_back(vector<int>());
        output[depth].push_back(root->val);
        dfs(root->left, output, depth + 1);
        dfs(root->right, output, depth + 1);
    }
};

// 32-3
// DFS
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> output;
        dfs_left(root, output, 0);
        dfs_right(root, output, 0);
        return output;
    }

    void dfs_left(TreeNode* root, vector<vector<int>>& output, int depth) {
        if(! root) 
            return;
        if(output.size() <= depth)
            output.emplace_back(vector<int>());
        if(depth % 2 ==0)
            output[depth].emplace_back(root->val);
        dfs_left(root->left, output, depth + 1);
        dfs_left(root->right, output, depth + 1);
    }

    void dfs_right(TreeNode* root, vector<vector<int>>& output, int depth) {
        if(! root) 
            return;
        if(output.size() <= depth)
            output.emplace_back(vector<int>());
        if(depth % 2 ==1)
            output[depth].emplace_back(root->val);
        dfs_right(root->right, output, depth + 1);
        dfs_right(root->left, output, depth + 1);
    }
};

// BFS
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(! root)
            return {};

        vector<vector<int>> output;
        deque<TreeNode*> q;
        q.push_back(root);
        int level = 0;
        while(! q.empty()) {
            vector<int> cur;
            deque<TreeNode*> cq;
            while(!q.empty()) {
                cq.push_back(q.front());
                q.pop_front();
            }
            if(level % 2 == 0) {
                while(!cq.empty())  {
                    cur.push_back(cq.front()->val);
                    if(cq.front()->left)
                        q.push_back(cq.front()->left);
                    if(cq.front()->right)
                        q.push_back(cq.front()->right);
                    cq.pop_front();
                }
            }
            else {
                while(!cq.empty()) {
                    cur.push_back(cq.back()->val);
                    if(cq.back()->right)
                        q.push_front(cq.back()->right);
                    if(cq.back()->left) 
                        q.push_front(cq.back()->left);
                    cq.pop_back();
                }
            }
            level++;
            output.emplace_back(cur);
            
        }
        return output;
    }
};

// 33 
// 知识点：1. 二叉搜索树  2. 后序遍历返回的数组应该如何划分  3.递归
// 需要复习
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return verifysub(0, postorder.size()-1, postorder);
    }

    bool verifysub(int l, int r, vector<int>& postorder) {
        if(l >= r) 
            return true;

        int rootval = postorder[r];
        int nr = l;
        while(postorder[nr] < rootval && nr < r)
            nr++;
        for(int i = nr + 1; i < r; i++) {
            if(postorder[i] < rootval)
                return false;
        }
        
        return verifysub(l, nr-1, postorder) && verifysub(nr, r-1, postorder);
    }
};

// 34
// 别忘了递归退出时pop最后一位
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
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if(!root)
            return {};
        vector<vector<int>> output;
        vector<int> ans;
        dfs(root, target, ans, output);
        return output;
    }

    void dfs(TreeNode* root, int target, vector<int>& ans, vector<vector<int>>& output) {
        if(target - root->val != 0 && root->left==nullptr && root->right==nullptr)
            return;

        ans.push_back(root->val);
        if(target - root->val == 0 && root->left==nullptr && root->right==nullptr)      
            output.push_back(ans);
        else {
            if(root->left)
                dfs(root->left, target - root->val, ans, output);
            if(root->right)
                dfs(root->right, target - root->val, ans, output);
        }
        ans.pop_back();
    }
};

// 35
// 主要是理解题意，不过当前实现的算法可优化的地方较多，效率不是很高
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return {};

        unordered_map<Node*, Node*> hash;

        Node* dummy = new Node(-1);
        Node* h = head;
        Node* pre = dummy;
        while(head) {
            Node* cur = new Node(head->val);
            hash[head] = cur;
            pre->next = cur;
            pre = cur;
            head = head->next;
        }
        pre = dummy->next;
        while(h) {
            if(h->random)
                pre->random = hash[h->random];
            h = h->next;
            pre = pre->next;
        }
        return dummy->next;
    }
};

// 37
// 字符串还是不熟练，有些实现函数不知道，得找时间把string看一遍
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return {};

        string s;
        queue<TreeNode*> level;
        level.push(root);
        while(!level.empty()) {
            TreeNode* cur = level.front();
            level.pop();
            if(cur) {
                s.append(to_string(cur->val) + ' ');
                level.push(cur->left);
                level.push(cur->right);
            }
            else
                s.append("* ");
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)
            return {};

        vector<string> dlist;
        string num;
        for(auto& c: data) {
            if(c == ' ') {
                dlist.push_back(num);
                num.clear();
                continue;
            }
            num.push_back(c);
        }

        TreeNode* root = new TreeNode(stoi(dlist[0]));
        queue<TreeNode*> tree;
        tree.push(root);
        int i = 0;
        TreeNode* cur;
        while(!tree.empty()) {
            cur = tree.front();
            tree.pop();
            if(dlist[i+1] != "*") {
                TreeNode* left = new TreeNode(stoi(dlist[i+1]));
                cur->left = left;
                tree.push(left);
            } 
            if(dlist[i+2] != "*") {
                TreeNode* right = new TreeNode(stoi(dlist[i+2]));
                cur->right = right;
                tree.push(right);
            }    
            i+=2;
        }
        return root;
    }
};

// 38
// 非常巧妙地用交替避免了额外的储存位置
// 另一种解法是用字典序，首先用所给字符串找到最小字典序，然后一直找更大一点的字典序，直到没有更大的字典序
class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> ans;
        dfs(s, 0, ans);
        return ans;
    }

    void dfs(string& s, int l, vector<string>& ans) {
        if(l == s.size()-1) {
            ans.push_back(s);
            return;
        }

        set<int> same;
        for(int i = l; i < s.size(); i++) {
            if(same.find(s[i]) != same.end())
                continue;
            same.insert(s[i]);
            swap(s[l], s[i]);
            dfs(s, l+1, ans);
            swap(s[l], s[i]);
        }
    }
};

// 39
// 复习了一下快排，归并排序，并用的迭代版本
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        nums = mergesort(nums);
        return nums[n/2];
    }

    void quicksort(vector<int>& nums, int l, int r) {
        if(l>=r)
            return;
        int c = nums[l];
        int index = l+1;
        for(int i = l+1; i<= r; i++) {
            if(nums[i] < c) {
                swap(nums[i], nums[index]);
                index++;
            }
        }
        swap(nums[l],nums[index-1]);

        if(l < r) {
            quicksort(nums, l, index - 2);
            quicksort(nums, index, r);
        }
        return;
    }

    vector<int> mergesort(vector<int> nums) {
        int n = nums.size();
        vector<int> ncopy(n);
        for(int i = 1; i < n; i+= i) {
            for(int j = 0; j < n; j += i*2 ) {
                int low = j, mid = min(j+i, n), high = min(j+i*2,n);
                int start1 = low, end1 = mid;
                int start2 = mid, end2 = high;
                while(start1 < end1 && start2 < end2)
                    ncopy[low++] = nums[start1] < nums[start2]? nums[start1++]: nums[start2++];
                while(start1 < end1)
                    ncopy[low++] = nums[start1++];
                while(start2 < end2)
                    ncopy[low++] = nums[start2++];
            }
            nums = ncopy;
        }
        return nums;
    }
};

// 40
// 最小(大）堆问题，但优先队列用的还不够熟练，关键点priority_queue<type, container, comparefunction>
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(k < 1)
            return {};
        int n = arr.size();
        priority_queue<int> q;
        for(int i = 0; i < k; i++) 
            q.push(arr[i]);

        for(int j = k; j < n; j++) {
            if(q.top() > arr[j]) {
                q.pop();
                q.push(arr[j]);
            }
        }
        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.top());
            q.pop();
        }
        return ans;
    }
};
