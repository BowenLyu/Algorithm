// No.1
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hm;
        int n = nums.size();
        hm[nums[0]] = 0;
        for(int i = 1; i < n; i++)
        {
            if(hm.count(target - nums[i]))
                return vector<int>{hm[target - nums[i]], i};
            hm[nums[i]] = i;
        }
        return {};
    }
};

// No.2
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// 这种解法无法处理大数，int类型的位数不够
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num1 = list2num(l1);
        int num2 = list2num(l2);
        int num = num1 + num2;
        ListNode* list = num2list(num);
        return list;
    }

    int list2num(ListNode* list){
        int num = 0;
        int dg = 0;
        if(list == NULL)
            return num;
        while(list){
            num += list->val * pow(10, dg);
            list = list->next;
            dg++;
        }
        return num;
    }

    ListNode* num2list(int num){
        ListNode* list = new ListNode();
        ListNode* cur;
        int dg = 1;
        if(!num)
        {
            list->val =0;
            return list;
        }
        cur = list;
        int cnum;
        do{
            ListNode* newnode = new ListNode(); 
            cnum = num % 10;
            newnode->val = cnum;
            cur->next = newnode;
            cur = newnode;
            num = (num - cnum) / 10;
        }while(num != 0);
        return list->next;
    }
};

// 另一种
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* list = new ListNode();
        ListNode* cur = list;

        int sum = 0;
        int last = 0;
        int l1val = 0;
        int l2val = 0;
        while(l1 || l2){
            ListNode* temp = new ListNode();
            if(l1){
                l1val = l1->val;
                l1 = l1->next;
            }
            else
                l1val = 0;
            if(l2){
                l2val = l2->val;
                l2 = l2->next;
            }
            else
                l2val = 0;

            sum = l1val + l2val + last;
            if(sum < 10){
                temp->val = sum;
                last = 0;
            }  
            else{
                temp->val = sum % 10;
                last = 1;
            }           
            cur->next = temp;
            cur = temp;
        }

        if(last){
            ListNode* lst = new ListNode();
            lst->val = last;
            cur->next = lst;
        }

        return list->next;
    }
};

// No.3
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0)
            return 0;
        vector<int> num(n);
        num[0] = 1;
        int max = 1;
        for(int i = 1; i < n; i++){
            int count = num[i-1];
            for(int j = i - num[i-1]; j < i; j++){
                if(s[j] == s[i]){
                    count -=  j - (i - num[i-1]) + 1;
                    continue;
                }
            }
            num[i] = count + 1;
            if(max < num[i])
                max = num[i];
        }
        return max;
    }
};

// No.5
// 递归超时
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        for(int i = n; i > 0; i--)
        {
            for(int j = 0; j < n + 1 - i; j++)
            {
                if(Palindrom(s.substr(j, i)))
                    return s.substr(j, i);
            }
        }
        return NULL;
    }

    bool Palindrom(string s){
        int n = s.size();
        if(n == 0 || n == 1)
            return true;
        if(s[0] != s[n-1])
            return false;
        if(! Palindrom(s.substr(1,n-2)))
            return false;

        return true;   
    }
};
//动态规划
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 0)
            return NULL;

        bool isPalindrome[n][n];
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j)
                    isPalindrome[i][j] = true;
                else
                    isPalindrome[i][j] = false;
            }
        }
            

        int length = 1;
        int begin = 0;
        
        for(int L = 2; L <= n; L ++)
        {
            for(int i = 0; i < n - L + 1; i++)
            {
                if(L == 2)
                {
                    if(s[i] == s[i + L -1] )
                    {
                        isPalindrome[i][i+L-1] = true;
                        if(length < L)
                        {
                            length = L;
                            begin = i;
                        }
                    }
                    
                }
                else
                {
                    if(isPalindrome[i+1][i+L-2])
                    {
                        if(s[i] == s[i + L -1] )
                    {
                        isPalindrome[i][i+L-1] = true;
                        if(length < L)
                        {
                            length = L;
                            begin = i;
                        }
                    }
                    }
                }

            }
        }

        return s.substr(begin, length);
    }

};

// No.9
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        vector<int> num;
        while(x != 0){
            num.push_back(x % 10);
            x = x / 10;
        }
        int n = num.size();
        for(int i = 0; i < n/2; i++){
            if(num[i] != num[n-1-i])
                return false;
        }
        return true;
    }
};

// No.21
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* all;
        
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;

        if(list1->val <= list2->val)
        {
            all = list1;
            list1 = list1->next;
        }        
        else
        {
            all = list2;
            list2 = list2->next;
        }
        ListNode* first = all;
        while(list1 && list2)
        {
            if(list1->val <= list2->val)
            {
                all->next = list1;
                list1 = list1->next;
            }
            else
            {
                all->next = list2;
                list2 = list2->next;
            }
            all = all->next;
        }
        if(list1 == NULL)
            all->next = list2;
        else
            all->next = list1;

        return first;
    }
};

// No.23
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int num = lists.size();
        if(num == 0)
            return NULL;

        while(num > 1){
            int j = 0;
            for(int i = 0; i < num; i+=2)
            {
                if( i+1 >= num){
                    lists[j] = merge2Lists(lists[i], NULL);
                    break;
                }
                lists[j] = merge2Lists(lists[i], lists[i+1]);
                j++;
            }

            num = num/2 + num%2;
        }
            
        return lists[0];
        
    }

    ListNode* merge2Lists(ListNode* list1, ListNode* list2){
        ListNode first(-1);
        ListNode* merge = &first;

        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;
        
        ListNode* temp = merge;

        while(list1 && list2)
        {
            if(list1->val <= list2->val)
            {
                temp->next = list1;
                list1 = list1->next;
            }
            else
            {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        
        if(list1)
            temp->next = list1;
        if(list2)
            temp->next = list2;

        return merge->next;
    }
};

// No.53
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int subsum[n];
        int maxsum = -10000;

        subsum[0] = nums[0];
        for(int i = 1; i < n; i++)
        {
            if(subsum[i-1] <= 0)
                subsum[i] = nums[i];
            else
                subsum[i] = subsum[i-1] + nums[i];
        }

        for(int j = 0; j < n; j++)
        {
            if(subsum[j] > maxsum)
                maxsum = subsum[j];
        }
        

        return maxsum;
    }
};

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

// No.70
//递归但超时
class Solution {
public:
    int climbStairs(int n) {
        return Fibonacci(n);
    }

    int Fibonacci(int n){
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        else
            return Fibonacci(n-1) + Fibonacci(n-2);
    }
};

//动态优化
class Solution {
public:
    int climbStairs(int n) {
        int a[n];

        if(n >= 1)
            a[0] = 1;
        if(n >= 2)
            a[1] = 2;

        for(int i = 2; i < n; i++)
            a[i] = a[i-1] + a[i-2];

        return a[n-1];
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

// No.118
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        pascal.resize(numRows);

        if(numRows>=1)
        {
            pascal[0].resize(1);
            pascal[0][0] = 1;
        }
        if(numRows>=2)
        {
            pascal[1].resize(2);
            pascal[1][0] = pascal[1][1] = 1;
        }
        if(numRows >= 3)
        {
            for(int i = 2; i < numRows; i++)
            {
                pascal[i].resize(i+1);
                pascal[i][0] = 1;
                pascal[i][i] = 1;
                for(int j = 1; j < i ; j++)
                {
                    pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
                }
            }
        }
        
        return pascal;
    }
};

// No.215
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        quicksort(nums, 0, n-1);
        return nums[k-1];
    }

    void quicksort(vector<int>& nums, int r, int l){
        if(r >= l)
            return;
        int std = nums[r];
        int i = r;
        int j = l;

        while(i != j){
            while(std > nums[j] && i < j)
                j--;
            while(std <= nums[i] && i < j)
                i++;
            
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        nums[r] = nums[i];
        nums[i] = std;

        quicksort(nums, r, i-1);
        quicksort(nums, i+1, l);
    }
};

// No.347
class Solution {
public:
    static bool cmp(pair<int, int>& m, pair<int, int>& n) {
        return m.second > n.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> cnt;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(cnt.count(nums[i])==0)
            {
                cnt[nums[i]] = 1;
                continue;
            }
            cnt[nums[i]]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int> >, decltype(&cmp) > pq(cmp);
        for(auto& [num, count]: cnt )
        {
            if(pq.size() == k)
            {
                if(count > pq.top().second)
                {
                    pq.pop();
                    pq.emplace(num, count);
                }

            }
            else{
                pq.emplace(num, count);
            }
        }
        vector<int> topk;
        while(! pq.empty())
        {
            topk.push_back(pq.top().first);
            pq.pop();
        }
        return topk;
    }
};
