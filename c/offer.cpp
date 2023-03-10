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
