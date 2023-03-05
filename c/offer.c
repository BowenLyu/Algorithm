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
