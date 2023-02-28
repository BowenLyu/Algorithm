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

// No.6
class Solution {
public:
    string convert(string s, int numRows) {
        string zigzag;
        int n = s.size();
        if(numRows < 2)
            return s;
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < n; j = j + 2*numRows-2){
                if(i + j < n)
                    zigzag.push_back(s[i + j]);
                if(i != 0 && i != numRows -1 && 2*numRows - 2 + j - i < n)
                    zigzag.push_back(s[2*numRows - 2 + j - i]);
            }
        }
        return zigzag;
    }
};

// No.7 
/* 关键在于推导rev的取值范围判断语句！ */
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            if (rev < INT_MIN / 10 || rev > INT_MAX / 10) {
                return 0;
            }
            int digit = x % 10;
            x /= 10;
            rev = rev * 10 + digit;
        }
        return rev;
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

// No.11
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_s = -1;

        while( left < right){
            int area = min(height[left], height[right]) * (right - left);
            max_s = max(area, max_s);
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        return max_s;
    }
};

// No.12
class Solution {
public:
    string intToRoman(int num) {
        string Roman;
        pair<int,string> n2r[] = {{1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}};
        for(auto& [n, s]: n2r){
            while(num >= n){
                Roman.append(s);
                num -= n;
            }
        }

        return Roman;
    }
};

// No.13
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman{{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};
        int n = s.size();
        int arabic = 0;
        for(int i = 0; i < n; i++){
            if(roman[s[i]] < roman[s[i+1]]){
                arabic += roman[s[i+1]] - roman[s[i]];
                i++;
            }
            else{
                arabic += roman[s[i]];
            }
        }
        return arabic;
    }
};

// No.14
// 注意 ["",""] 类型的空字符串
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string cp;
        int n = strs.size();
        int length = strs[0].size();
        int ind = 0;
        while(ind < length){
            char temp = strs[0][ind];
            for(int i = 1; i < n; i++){
                if(strs[i][ind] != temp)
                    return cp;
            }
            cp.push_back(temp);
            ind++;
        }
        return cp;
    }
};

// No.15
// 耗时巨大，且自己的解强行使用hash并不好，下面实现的算法没有避免多次计算的问题。
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ts;
        map<int,int> n_n;
        
        for(int i = 0; i < n; i++)
            n_n[nums[i]]++;

        if(n_n.begin()->first > 0)
                return ts;

        if(n_n.count(0)){
            if(n_n[0] >= 3){
            vector<int> temp{0,0,0};
            ts.push_back(temp);
            }
        }

        for(map<int,int>::iterator iter = n_n.begin();iter != n_n.end(); iter++){
            map<int, int>::iterator iter2 = n_n.end();
            for(iter2--; iter2 != iter; iter2--){
                if(iter->first < 0 && iter2->first > 0){
                    if(-(iter->first + iter2->first) == iter->first){
                        if(iter->second > 1){
                            vector<int> temp{iter->first, iter->first, iter2->first};
                            ts.push_back(temp);
                        }
                    }
                    else if(-(iter->first + iter2->first) == iter2->first){
                        if(iter2->second > 1){
                            vector<int> temp{iter->first, iter2->first, iter2->first};
                            ts.push_back(temp);
                        }
                    }
                    else{
                        if(-(iter->first + iter2->first) > iter->first && -(iter->first + iter2->first) < iter2->first){
                            if(n_n.count(-(iter->first + iter2->first))){
                            vector<int> temp{iter->first, -(iter2->first + iter->first), iter2->first};
                            ts.push_back(temp);
                            }
                        }
                    }
                }
            }
        }
            return ts;
        }
};

// No.16
// 双指针，不过不知道这里是不是因为没有用中间变量，导致重复的计算步骤耗时过多？
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int ans = 0;
        int best = INT_MAX;
        for(int i = 0; i < nums.size() -2; i++){
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                if(nums[i] + nums[left] + nums[right] == target)
                    return target;
                else if(abs(nums[i] + nums[left] + nums[right] - target) < best){
                    best = abs(nums[i] + nums[left] + nums[right] - target);
                    ans = nums[i] + nums[left] + nums[right];
                }
                if(nums[i] + nums[left] + nums[right] > target )
                    right--;
                else
                    left++;
            }
        }
        return ans;
        
    }
};

// No.17
// 对字符串的操作还是不是很熟悉
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> pn{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        if(digits.empty())
            return {};

        vector<string> output{""};
        vector<string> temp;
        for(auto& a: digits){
            string s = pn[a - '0'];
            for(auto& b: s){
                for(auto& c: output){
                    temp.push_back(c + b);
                }
            }
            output = temp;
            temp.clear();
        }
        return output;
    }
};

// No.18
// 也可不用set。加入多个是否相同判断。
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        if(n < 4)
            return {};

        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        set<vector<int>> s;
        for(int i = 0; i < n - 3; i++){
            for(int j = i + 1; j < n - 2; j++){
                int l = j + 1;
                int r = n - 1;
                long long diff = target - (long long)nums[i] - (long long)nums[j];
                while(l < r){
                    long long sumlr = (long long)nums[l] + (long long)nums[r];
                    if(sumlr == diff){
                        vector<int> temp{nums[i], nums[j], nums[l], nums[r]};
                        s.insert(temp);
                        l++;
                        r--;
                    }
                    else if(sumlr < diff)
                        l++;
                    else
                        r--;

                }
            }
        }
        for(auto& e: s)
            output.push_back(e);
        return output;
    }
};

// No.19
// 注意使用哑节点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* cut = dummy;
        ListNode* cur = head;

        for(int i = 0; i < n; i++)
            cur = cur->next;

        while(cur){
            cur = cur->next;
            cut = cut->next;
        }
        cut->next = (cut->next)->next;
        ListNode* ans = dummy->next;
        delete dummy;

        return ans;
    }
};

// No.20
class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 == 1)
            return false;

        unordered_map<char,int> h{{'(',-1}, {')',1}, {'{',-2}, {'}',2}, {'[',-3}, {']',3}};
        stack<char> ss;
        for(int i = 0; i < s.size(); i++){
            if(h[s[i]] < 0)
                ss.push(s[i]);
            else{
                if(ss.empty())
                    return false;
                char temp = ss.top();
                if(h[temp] + h[s[i]] == 0)
                    ss.pop();
                else
                    return false;
            }
        }
        if(!ss.empty())
            return false;
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

// No.22
// 递归，左边不小于右边
class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        vector<string> ().swap(ans);
        if(n == 0)
            return {};
        
        genParenthesis("", n, n);
        return ans;
        
    }

    void genParenthesis(string o, int l, int r){
        if(l == 0 && r == 0){
            ans.push_back(o);
            return;
        }
        if(l == r){
            genParenthesis(o + '(', l-1, r);
        }
        else{
            if(l > 0)
                genParenthesis(o + '(', l-1, r);
            genParenthesis(o + ')', l, r-1);
        }
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

// No.24
// 这个也能递归！
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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode* temp2 = head->next;
        if(temp2 == NULL)
            return head;

        ListNode* temp1 = head;
        ListNode* new_head = temp2;
        ListNode* end = new ListNode(0);
        while(temp1 && temp2){
            end->next = temp2;
            temp1->next = temp2->next;
            temp2->next = temp1;
            end = temp1;
            temp1 = temp1->next;
            if(temp1)
                temp2 = temp1->next;
            else
                return new_head;
        }
        return new_head;
    }
};

//No.25
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
// 这个解法会有内存问题，暂时还不清楚原因
// class Solution {
// public:
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         stack<ListNode*> reverseKList;
//         ListNode* dummy = new ListNode(-1, head);
//         ListNode* cur = head;
//         ListNode* end = dummy;

//         while(cur){
//             int count = 0;
//             for(int i = 0; i < k; i++){
//                 if(cur){
//                     reverseKList.push(cur);
//                     cur = cur->next;
//                     count++;
//                 }
//                 else
//                     return dummy->next;
//             }

//             while(!reverseKList.empty()){
//                 ListNode* temp = reverseKList.top();
//                 reverseKList.pop();
//                 end->next = temp;
//                 end = end->next;
//             }
//         }
//         return dummy->next;
//     }
// };

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<ListNode*> reverseKList;
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = head;
        ListNode* end = dummy;

        while(cur){
            int count = 0;
            for(int i = 0; i < k; i++){
                if(cur){
                    reverseKList.push(cur);
                    cur = cur->next;
                    count++;
                }
                else{
                    while(! reverseKList.empty()){
                        cur = reverseKList.top();
                        reverseKList.pop();
                    }
                    end->next = cur;
                    return dummy->next;
                }
            }

            while(!reverseKList.empty()){
                ListNode* temp = reverseKList.top();
                reverseKList.pop();
                end->next = temp;
                end = end->next;
                end->next = NULL;   //这个地方必须要加上尾指针指向NULL才不会报指向释放内存的错误，暂时不知道原因 https://blog.csdn.net/cncxycpp/article/details/106057900
            }
        }
        return dummy->next;
    }
};

// No.26
// 还可以使用双指针，空间复杂度为O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur = nums[0] - 1;
        int count = 0;
        vector<int> new_nums;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != cur){
                new_nums.push_back(nums[i]);
                cur = nums[i];
                count++;
            }
        }
        nums = new_nums;
        return count;
    }
};

// No.27
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int end = n - 1;
        for(int i = 0; i <= end; i++){
            if(nums[i] == val){
                while(nums[end] == val && end > i)
                    end--;
                nums[i] = nums[end];
                nums[end] = val;
                end--;
            }
        }
        return end + 1;
    }
};

// No.28
// KMP算法实现，挺好理解的，但是需要动笔写写。
class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> kmptable = KMP(needle);

        int n = haystack.size();
        int m = needle.size();
        int i = 0;
        while(i <= n - m){
            int count = 0;
            while(haystack[i] == needle[count]){
                i++;
                count++;
                if(count == m)
                    return i-m;
            }
            if(count > 0)
                i = i - kmptable[count - 1];
            else
                i++;
        }
        return -1;
    }

    vector<int> KMP(string match){
        int n = match.size();
        vector<int> kmptable(n);
        // kmptable.resize(n);
        kmptable[0] = 0;

        for(int i = 1; i < n; i++){
            int now = kmptable[i - 1];
            while(now >= 0 && match[i] != match[kmptable[now]])
                now--;
            kmptable[i] = now + 1;
        }
        return kmptable;
    }
};

// No.29
//位运算以及int，long类型的理解
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN) {
            if (divisor == 1) {
                return INT_MIN;
            }
            if (divisor == -1) {
                return INT_MAX;
            }
        }
        // 考虑除数为最小值的情况
        if (divisor == INT_MIN) {
            return dividend == INT_MIN ? 1 : 0;
        }
        // 考虑被除数为 0 的情况
        if (dividend == 0) {
            return 0;
        }

        int flag1 = 0;
        int flag2 = 0;
        long ldividend = dividend;
        long ldivisor = divisor;

        if(dividend < 0){
            ldividend = -ldividend;
            flag1 = 1;
        } 
        if(divisor < 0){
            ldivisor = -ldivisor;
            flag2 = 1;
        }
        long output = 0;
        for(int i = 31; i >= 0; i--){
            if(ldividend >= ldivisor<<i){
                output += 1<<i;
                ldividend -= ldivisor<<i;
            }
        }

        if(flag1 ^ flag2)
            return -output;
        else
            return output;
    }
};

// No.31
// 需要掌握字典序
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return;
        int i = n - 2;
        while(i >= 0 && nums[i] >= nums[i+1])
            i--;
        
        if(i >= 0){
            int j = n - 1;
            while(j > 0 && nums[j] <= nums[i])
                j--;
            
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        int l = i + 1;
        int r = n - 1;
        while(l > r){
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
            l++;
            r--;
        }
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
