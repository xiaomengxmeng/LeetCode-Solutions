# 📋 周复习答题模板汇总 — 28 题

> 来源：2026-06-01 ~ 2026-06-05 五天密集周复习
> 状态：28/28 全部一次通过 ✅

---

## 总览

| # | 题号 | 题目 | 技巧 | 组 |
|:-:|:---:|:-----|:-----|:-:|
| 1 | 1 | Two Sum | 哈希表一遍扫描 | 组1 |
| 2 | 3 | Longest Substring | 滑动窗口（变长） | 组1 |
| 3 | 56 | Merge Intervals | 排序 + 逐个合并 | 组2 |
| 4 | 283 | Move Zeroes | 快慢双指针 | 组2 |
| 5 | 206 | Reverse Linked List | 三指针反转 | 组3 |
| 6 | 142 | Linked List Cycle II | 快慢指针两阶段 | 组3 |
| 7 | 234 | Palindrome Linked List | 找中点 + 反转后半 | 组3 |
| 8 | 19 | Remove Nth Node | dummy + 快慢间隔n | 组3 |
| 9 | 739 | Daily Temperatures | 单调递减栈存下标 | 组4 |
| 10 | 503 | Next Greater Element II | 循环数组单调栈 | 组4 |
| 11 | 42 | Trapping Rain Water | 单调栈按行计算 | 组4 |
| 12 | 34 | Find First and Last | lower_bound 两次 | 组5 |
| 13 | 33 | Search in Rotated Array | 分段二分 | 组5 |
| 14 | 875 | Koko Eating Bananas | 二分答案 | 组5 |
| 15 | 102 | Level Order Traversal | BFS 按层 queue | 组6 |
| 16 | 98 | Validate BST | 范围递归 + 中序迭代 | 组6 |
| 17 | 105 | Construct from Pre+In | 前序定根+中序分左右 | 组6 |
| 18 | 236 | LCA of Binary Tree | 后序查找 | 组6 |
| 19 | 437 | Path Sum III | 前缀和+hashmap+回溯 | 组7 |
| 20 | 543 | Diameter of BT | 后序求高度+全局直径 | 组7 |
| 21 | 200 | Number of Islands | 网格 DFS 水淹法 | 组8 |
| 22 | 207 | Course Schedule | 三色 DFS 检环 | 组8 |
| 23 | 130 | Surrounded Regions | 边界 DFS + 逆向填充 | 组8 |
| 24 | 994 | Rotting Oranges | 多源 BFS 分层计时 | 组9 |
| 25 | 542 | 01 Matrix | 多源 BFS 直接存距离 | 组9 |
| 26 | 46 | Permutations | 回溯 + used 数组 | 组10 |
| 27 | 39 | Combination Sum | 回溯 + 排序剪枝 | 组10 |
| 28 | 79 | Word Search | 网格回溯 + 原数组标记 | 组10 |

---

# 组1：哈希表 + 滑动窗口

---

### [1] Two Sum — 哈希表一遍扫描

**核心思想**：遍历时查 target - nums[i] 是否已在 map 中，在则返回，不在则存入。

```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        int need = target - nums[i];
        if (map.count(need)) return {map[need], i};
        map[nums[i]] = i;
    }
    return {};
}
```

**关键点**：
- 先查再存，避免自己和自己匹配
- `map.count(key)` 比 `map.find(key) != map.end()` 更简洁

---

### [3] Longest Substring Without Repeating Characters — 滑动窗口（变长）

**核心思想**：右边界扩张，频率 > 1 时左边界收缩，每次更新最大长度。

```cpp
int lengthOfLongestSubstring(string s) {
    vector<int> freq(128, 0);
    int left = 0, ans = 0;
    for (int right = 0; right < s.size(); right++) {
        freq[s[right]]++;
        while (freq[s[right]] > 1)   // 窗口内有重复字符
            freq[s[left++]]--;        // 左边界收缩
        ans = max(ans, right - left + 1);
    }
    return ans;
}
```

**关键点**：
- `freq[128]` 覆盖全部 ASCII
- `while` 不是 `if`：可能有多个重复字符需要连续收缩

---

# 组2：双指针 + 排序合并

---

### [56] Merge Intervals — 排序 + 逐个合并

**核心思想**：按起点排序，用 cur 记录当前区间，逐个判断是否重叠。

```cpp
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    vector<int> cur = intervals[0];
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= cur[1])
            cur[1] = max(intervals[i][1], cur[1]);  // 合并
        else {
            res.push_back(cur);
            cur = intervals[i];
        }
    }
    res.push_back(cur);  // 最后一个别忘
    return res;
}
```

**关键点**：
- `sort` 默认按第一维升序（起点排序）
- 最后一定要 `res.push_back(cur)`，否则少一个区间

---

### [283] Move Zeroes — 快慢双指针原地移动

**核心思想**：fast 遍历找非零，slow 记录放置位置；剩余位置填零。

```cpp
void moveZeroes(vector<int>& nums) {
    int slow = 0;
    for (int fast = 0; fast < nums.size(); fast++)
        if (nums[fast] != 0)
            nums[slow++] = nums[fast];   // 非零元素前移
    while (slow < nums.size())
        nums[slow++] = 0;                // 后面补零
}
```

**关键点**：
- slow 一边放一边前进，最终指向"第一个零的位置"
- 相对顺序不变（稳定移动）

---

# 组3：链表四件套

---

### [206] Reverse Linked List — 三指针反转

**核心思想**：prev/cur/next 三步走，先保存 next 再反转。

```cpp
ListNode* reverseList(ListNode* head) {
    ListNode *prev = nullptr, *cur = head;
    while (cur) {
        ListNode* next = cur->next;  // 1. 先保存
        cur->next = prev;            // 2. 反转指向
        prev = cur;                  // 3. prev 前移
        cur = next;                  // 4. cur 前移
    }
    return prev;
}
```

**关键点**：
- 四步顺序不可乱：保存 → 反转 → 前移prev → 前移cur
- 返回 `prev`（新头），不是 `cur`（cur 是 nullptr）

---

### [142] Linked List Cycle II — 快慢指针两阶段法

**核心思想**：阶段1 快慢指针相遇 → 阶段2 头指针和相遇点同时走。

```cpp
ListNode* detectCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    // 阶段1：找相遇点
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    if (!fast || !fast->next) return nullptr;  // 无环
    // 阶段2：找环入口
    ListNode *p1 = head, *p2 = slow;
    while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}
```

**关键点**：
- 循环条件用 `&&` 不用 `||`
- 无环判断：`!fast || !fast->next`
- 数学原理：`头→入口 = 相遇点→入口`

---

### [234] Palindrome Linked List — 找中点 + 反转后半

**核心思想**：快慢找中点 → 反转后半 → 双指针比较。

```cpp
bool isPalindrome(ListNode* head) {
    // 1. 找中点
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // 2. 反转后半
    ListNode *prev = nullptr, *cur = slow;
    while (cur) {
        ListNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    // 3. 比较
    ListNode *left = head, *right = prev;
    while (right) {
        if (left->val != right->val) return false;
        left = left->next;
        right = right->next;
    }
    return true;
}
```

**关键点**：
- 奇数个节点时，后半长比前半短 1（中点在后半）
- 比较时用 `while (right)` 而非 `while (left)`

---

### [19] Remove Nth Node From End — dummy + 快慢间隔 n 步

**核心思想**：fast 先走 n 步，然后 fast/slow 一起走到尾，slow 刚好在待删节点的前驱。

```cpp
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0, head);
    ListNode *slow = dummy, *fast = dummy;
    for (int i = 0; i < n; i++)      // fast 先走 n 步
        fast = fast->next;
    while (fast->next) {             // 一起走到尾
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;    // 删除
    return dummy->next;
}
```

**关键点**：
- dummy 不可或缺：头节点可能被删除
- fast 先走 n 步（不是 n-1），这样 slow 停在待删节点的**前一个**

---

# 组4：单调栈三连

---

### [739] Daily Temperatures — 单调递减栈存下标

**核心思想**：维护栈内温度递减，遇到更高温度时弹出并记录天数差。

```cpp
vector<int> dailyTemperatures(vector<int>& t) {
    vector<int> res(t.size(), 0);
    stack<int> st;  // 存下标
    for (int i = 0; i < t.size(); i++) {
        while (!st.empty() && t[st.top()] < t[i]) {
            int top = st.top(); st.pop();
            res[top] = i - top;         // 天数差
        }
        st.push(i);
    }
    return res;
}
```

**关键点**：
- 栈存下标而非温度值（需要计算距离）
- 栈内始终递减：栈底→栈顶 温度降低

---

### [503] Next Greater Element II — 循环数组单调栈

**核心思想**：遍历 2n 次模拟循环，只在第一圈入栈。

```cpp
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st;  // 存下标
    for (int i = 0; i < n * 2; i++) {
        int idx = i % n;
        while (!st.empty() && nums[st.top()] < nums[idx]) {
            int top = st.top(); st.pop();
            res[top] = nums[idx];
        }
        if (i < n) st.push(i);  // 只在第一圈入栈！
    }
    return res;
}
```

**关键点**：
- `if (i < n) st.push(i)` — 第二圈只查不存
- 循环数组用 `i % n` 取模

---

### [42] Trapping Rain Water — 单调递增栈按行计算

**核心思想**：遇到高于栈顶的柱子时，栈顶 = 凹槽底部，宽度 = 左右边界距离。

```cpp
int trap(vector<int>& height) {
    int res = 0, n = height.size();
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && height[st.top()] < height[i]) {
            int bottom = st.top(); st.pop();  // 凹槽底部
            if (st.empty()) break;            // 无左边界
            int w = i - st.top() - 1;         // 宽度
            int h = min(height[st.top()], height[i]) - height[bottom];  // 高度
            res += w * h;
        }
        st.push(i);
    }
    return res;
}
```

**关键点**：
- `st.empty()` 时 break：没有左边界接不住水
- 按行累加：每层水单独算

---

# 组5：二分查找三形态

---

### [34] Find First and Last Position — lower_bound 两次

**核心思想**：`lower_bound(target)` 找第一个 `>= target` 的位置；`lower_bound(target+1)` 找第一个 `> target` 的位置，右边界 = 后者 - 1。

```cpp
int lower_bound(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return left;  // 第一个 >= target 的位置
}

vector<int> searchRange(vector<int>& nums, int target) {
    int L = lower_bound(nums, target);
    int R = lower_bound(nums, target + 1);
    if (L == R) return {-1, -1};        // 没找到
    return {L, R - 1};
}
```

**关键点**：
- 循环条件 `<=`（不是 `<`），right 初始 `size()-1`
- `lower_bound(target+1)` 巧妙找右边界

---

### [33] Search in Rotated Sorted Array — 分段判断

**核心思想**：判断 mid 落在左段还是右段（与 `nums[0]` 比较），再判断 target 在段的哪一侧。

```cpp
int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;

        if (nums[0] <= nums[mid]) {          // mid 在左段
            if (nums[0] <= target && target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        } else {                             // mid 在右段
            if (nums[mid] < target && target <= nums.back())
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1;
}
```

**关键点**：
- `nums[0] <= nums[mid]` 判断 mid 在左段（注意等号，mid 可能就是 0）
- 右段判断用 `nums.back()` 而不是 `nums[0]`

---

### [875] Koko Eating Bananas — 二分答案

**核心思想**：二分猜速度 k，验证是否能在 h 小时内吃完。

```cpp
int minEatingSpeed(vector<int>& piles, int h) {
    int left = 1, right = *max_element(piles.begin(), piles.end());
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canEat(mid, piles, h))
            right = mid;         // 可以更慢
        else
            left = mid + 1;      // 必须更快
    }
    return left;
}

bool canEat(int k, vector<int>& piles, int h) {
    long long count = 0;
    for (int p : piles)
        count += (p + k - 1) / k;   // ceil(p / k)
    return count <= h;
}
```

**关键点**：
- `left` 从 1 开始（不是 0，0 会除零）
- `while (left < right)` + `right = mid` — 找最小可行解
- 向上取整：`(p + k - 1) / k`

---

# 组6：二叉树 DFS / BFS

---

### [102] Binary Tree Level Order Traversal — BFS 按层 queue

**核心思想**：队列 + 每层先记录 size，按层收集。

```cpp
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();         // 当前层节点数
        vector<int> level;
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front(); q.pop();
            level.push_back(node->val);
            if (node->left)  q.push(node->left);
            if (node->right) q.push(node->right);
        }
        res.push_back(level);
    }
    return res;
}
```

**关键点**：
- `int size = q.size()` 必须先记录，for 循环内 q 在变化
- 空树直接返回 `{}`

---

### [98] Validate BST — 范围递归 + 中序迭代（双模板）

**模板A：范围递归**
```cpp
bool isValidBST(TreeNode* root) {
    return dfs(root, LONG_MIN, LONG_MAX);
}
bool dfs(TreeNode* root, long long lower, long long upper) {
    if (!root) return true;
    if (root->val <= lower || root->val >= upper) return false;
    return dfs(root->left, lower, root->val)
        && dfs(root->right, root->val, upper);
}
```

**模板B：中序迭代**
```cpp
bool isValidBST(TreeNode* root) {
    stack<TreeNode*> st;
    TreeNode *cur = root, *prev = nullptr;
    while (!st.empty() || cur) {
        while (cur) { st.push(cur); cur = cur->left; }  // 一路向左
        cur = st.top(); st.pop();
        if (prev && cur->val <= prev->val) return false;
        prev = cur;
        cur = cur->right;
    }
    return true;
}
```

**关键点**：
- 范围法用 `long long` 防 INT_MIN/INT_MAX 边界
- 中序法：BST 中序遍历结果必严格递增

---

### [105] Construct Binary Tree from Preorder and Inorder — 前序定根 + 中序分左右

**核心思想**：前序第一个是根 → 在中序中找到根的位置（hashmap 加速）→ 左边是左子树，右边是右子树。`pre_idx` 必须传引用。

```cpp
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> in_map;
    for (int i = 0; i < inorder.size(); i++)
        in_map[inorder[i]] = i;
    int pre_idx = 0;
    return build(preorder, 0, inorder.size() - 1, pre_idx, in_map);
}

TreeNode* build(vector<int>& pre, int inL, int inR,
                int& pre_idx, unordered_map<int,int>& in_map) {
    if (inL > inR) return nullptr;
    int val = pre[pre_idx++];
    TreeNode* root = new TreeNode(val);
    int mid = in_map[val];
    root->left  = build(pre, inL, mid - 1, pre_idx, in_map);
    root->right = build(pre, mid + 1, inR, pre_idx, in_map);
    return root;
}
```

**关键点**：
- `pre_idx` 必须传**引用**（`int&`），递归时全局递增
- 必须先构建左子树（前序中左子树节点在右子树之前）

---

### [236] Lowest Common Ancestor of a Binary Tree — 后序查找

**核心思想**：后序遍历，遇到 p 或 q 直接返回；左子树和右子树各找到一个 → 当前节点就是 LCA。

```cpp
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left  = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (!left)  return right;   // 全在右子树
    if (!right) return left;    // 全在左子树
    return root;                 // 分居两侧 → 当前节点是 LCA
}
```

**关键点**：
- 只有 5 行核心代码
- `if (!left) return right` — 包含了 `left == right == nullptr` 的情况

---

# 组7：树上前缀和 + 全局后序

---

### [437] Path Sum III — 前缀和 + hashmap + 回溯

**核心思想**：维护根到当前节点的前缀和，查找 `curr_sum - targetSum` 在之前路径中出现过的次数。回溯恢复 map。

```cpp
int pathSum(TreeNode* root, int targetSum) {
    unordered_map<long long, int> map;
    map[0] = 1;  // 处理根到当前整条路径 = target 的情况
    int count = 0;
    dfs(root, 0, targetSum, map, count);
    return count;
}

void dfs(TreeNode* root, long long curr, int target,
         unordered_map<long long, int>& map, int& count) {
    if (!root) return;
    curr += root->val;
    count += map[curr - target];   // 找到了以当前节点结尾的路径
    map[curr]++;                   // 加入当前前缀和
    dfs(root->left, curr, target, map, count);
    dfs(root->right, curr, target, map, count);
    map[curr]--;                   // 回溯！
}
```

**关键点**：
- `map[0] = 1` 不可缺
- `long long` 防溢出（key 和 value 都要）
- 回溯 `map[curr]--` 保证不同分支互不干扰

---

### [543] Diameter of Binary Tree — 后序求高度 + 全局直径

**核心思想**：后序遍历求高度，在每层"顺便"更新全局直径 `L + R`。

```cpp
int diameterOfBinaryTree(TreeNode* root) {
    int ans = 0;
    dfs(root, ans);
    return ans;
}

int dfs(TreeNode* root, int& ans) {
    if (!root) return 0;
    int L = dfs(root->left, ans);
    int R = dfs(root->right, ans);
    ans = max(ans, L + R);        // 以当前节点为"拐点"的最长路径
    return max(L, R) + 1;         // 返回子树高度
}
```

**关键点**：
- 返回值 = 高度（单边最长），全局变量 = 直径（双边之和）
- `ans` 在返回前更新，利用了已计算好的 L 和 R

---

# 组8：图 DFS

---

### [200] Number of Islands — 网格 DFS 水淹法

**核心思想**：遍历遇到 `'1'` 就计数 + DFS 四方向淹掉整块陆地为 `'0'`。

```cpp
int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void dfs(vector<vector<char>>& grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()
        || grid[i][j] == '0')
        return;
    grid[i][j] = '0';                         // 淹没
    for (auto& d : dirs)
        dfs(grid, i + d[0], j + d[1]);
}

int numIslands(vector<vector<char>>& grid) {
    int res = 0;
    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[0].size(); j++)
            if (grid[i][j] == '1') { res++; dfs(grid, i, j); }
    return res;
}
```

**关键点**：
- 边界检查统一写在 DFS 开头一条 if
- 水淹法：直接修改原数组，无需 visited 数组
- 注意内外循环的变量名不要 shadow（内外都用 i/j 时仔细检查）

---

### [207] Course Schedule — 三色 DFS 检测有向环

**核心思想**：0=未访问（白），1=正在访问（灰），2=已访问（黑）。遇到灰色即发现环。

```cpp
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    for (auto& p : prerequisites)
        graph[p[1]].push_back(p[0]);   // 先修课 → 后修课

    vector<int> status(numCourses, 0); // 0=白, 1=灰, 2=黑
    for (int i = 0; i < numCourses; i++)
        if (status[i] == 0 && !dfs(graph, status, i))
            return false;
    return true;
}

bool dfs(vector<vector<int>>& graph, vector<int>& status, int node) {
    if (status[node] == 1) return false;  // 灰 → 环！
    if (status[node] == 2) return true;   // 黑 → 已确认无环
    status[node] = 1;                     // 标记灰
    for (int neighbor : graph[node])
        if (!dfs(graph, status, neighbor)) return false;
    status[node] = 2;                     // 标记黑
    return true;
}
```

**关键点**：
- 为什么需要三色：bool visited 分不清"正在访问"和"已访问完"
- 建图方向：`[课, 先修]` → `先修→课`（先修课指向后修课）

---

### [130] Surrounded Regions — 边界 DFS + 逆向填充

**核心思想**：从四边界的 `'O'` 开始 DFS 标记为 `'T'`（临时），然后全局 `'O'→'X'`（被包围的），`'T'→'O'`（还原连边界的）。

```cpp
void solve(vector<vector<char>>& board) {
    if (board.empty()) return;
    int m = board.size(), n = board[0].size();
    // Step 1: 从边界 O 出发 DFS，标记为 'T'
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if ((i==0 || j==0 || i==m-1 || j==n-1) && board[i][j]=='O')
                dfs(board, i, j);
    // Step 2: 遍历全图
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (board[i][j] == 'O')
                board[i][j] = 'X';        // 被包围的
            else if (board[i][j] == 'T')
                board[i][j] = 'O';        // 还原
}

void dfs(vector<vector<char>>& board, int i, int j) {
    if (i<0 || j<0 || i>=board.size() || j>=board[0].size()
        || board[i][j] != 'O')
        return;
    board[i][j] = 'T';
    for (auto& d : dirs) dfs(board, i + d[0], j + d[1]);
}
```

**关键点**：
- 逆向思维："不该改的"先标记 → 剩下的全改 → 还原标记
- `board.empty()` 提前判断防越界

---

# 组9：多源 BFS

---

### [994] Rotting Oranges — 多源 BFS 分层计时

**核心思想**：所有烂橘子同时入队，每扩散一层 = 1 分钟，用 fresh 计数提前结束。

```cpp
int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    queue<pair<int,int>> q;
    int fresh = 0, minutes = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == 2) q.push({i, j});
            else if (grid[i][j] == 1) fresh++;

    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    while (!q.empty() && fresh) {
        int size = q.size();
        while (size--) {
            auto [i, j] = q.front(); q.pop();
            for (auto& d : dirs) {
                int ni = i + d[0], nj = j + d[1];
                if (ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj]==1) {
                    grid[ni][nj] = 2; fresh--;
                    q.push({ni, nj});
                }
            }
        }
        minutes++;
    }
    return fresh == 0 ? minutes : -1;
}
```

**关键点**：
- `while(... && fresh)` 提前结束：新鲜橘子归零就无需继续
- `size` 循环实现分层：每层 = 1 分钟
- C++17 `auto [i, j] = q.front()` 结构化绑定

---

### [542] 01 Matrix — 多源 BFS 直接存距离

**核心思想**：所有 0 入队（距离 0），其余格子 `INT_MAX` 标记未访问。BFS 首次到达即最短距离。

```cpp
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> res(m, vector<int>(n, INT_MAX));
    queue<pair<int,int>> q;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (mat[i][j] == 0) {
                res[i][j] = 0;
                q.push({i, j});
            }

    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (auto& d : dirs) {
            int nx = x + d[0], ny = y + d[1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n
                && res[nx][ny] == INT_MAX) {
                res[nx][ny] = res[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return res;
}
```

**关键点**：
- 与 994 的区别：不需要分层（不用 size 循环），因为每个格子单独存距离
- `INT_MAX` 双用途：标记未访问 + 距离累加不溢出

---

# 组10：回溯三模板

---

### [46] Permutations — 回溯 + used 数组

**核心思想**：三层循环选数，用 `used[i]` 标记已选，到叶子节点收集结果。

```cpp
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> used(nums.size(), false);
    backtrack(nums, used, path, res);
    return res;
}

void backtrack(vector<int>& nums, vector<bool>& used,
               vector<int>& path, vector<vector<int>>& res) {
    if (path.size() == nums.size()) {
        res.push_back(path);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue;
        used[i] = true;
        path.push_back(nums[i]);
        backtrack(nums, used, path, res);
        used[i] = false;
        path.pop_back();
    }
}
```

**关键点**：
- 用 `used` 而非 `start`：排列中顺序重要
- 回溯三件套：标记 → 递归 → 撤销

---

### [39] Combination Sum — 回溯 + start + 排序剪枝

**核心思想**：排序后从 start 开始选（防重复组合），可重复选传 `i`。`sum + c[i] > target` 时 break 剪枝。

```cpp
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> path;
    sort(candidates.begin(), candidates.end());  // 排序是剪枝前提
    backtrack(candidates, 0, 0, path, res, target);
    return res;
}

void backtrack(vector<int>& c, int start, int sum,
               vector<int>& path, vector<vector<int>>& res, int target) {
    if (sum == target) { res.push_back(path); return; }
    for (int i = start; i < c.size(); i++) {
        if (sum + c[i] > target) break;       // 剪枝！
        path.push_back(c[i]);
        backtrack(c, i, sum + c[i], path, res, target);  // 传 i 可重复
        path.pop_back();
    }
}
```

**关键点**：
- 传 `i` 可重复选，传 `i+1` 不可重复（39 vs 78 的核心区别）
- `break` 不是 `continue`：升序后第一个超了后面的都超

---

### [79] Word Search — 网格回溯 + 原数组标记

**核心思想**：遍历每个格作起点，DFS 四方向搜索。`'#'` 标记已访问，回溯恢复。

```cpp
vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

bool exist(vector<vector<char>>& board, string word) {
    int m = board.size(), n = board[0].size();
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (dfs(board, word, 0, i, j)) return true;
    return false;
}

bool dfs(vector<vector<char>>& board, string& word, int k, int i, int j) {
    int m = board.size(), n = board[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n) return false;  // 越界
    if (board[i][j] != word[k]) return false;                // 不匹配
    if (k == word.size() - 1) return true;                   // 找到完整单词

    char temp = board[i][j];
    board[i][j] = '#';                                       // 标记已访问
    for (auto& d : dirs)
        if (dfs(board, word, k + 1, i + d[0], j + d[1]))
            return true;
    board[i][j] = temp;                                      // 回溯恢复
    return false;
}
```

**关键点**：
- 终止条件是 `k == word.size() - 1`（最后的字符也匹配了）
- 原数组 `'#'` 标记法省 visited 数组
- 找到即 `return true` 短路

---

# 🧠 技巧速查口诀

| 场景 | 口诀 |
|:-----|:-----|
| 找配对 | 哈希表查 target-num，先查后存 |
| 最长无重复子串 | 右扩 frq++，遇重复左缩 frq-- |
| 合并区间 | 按起点排序，cur 记录当前区间，结尾 push |
| 移动零 | 非零前移 slow++，末尾补零 |
| 反转链表 | 先保存 next，再反转，再前移 |
| 链表环入口 | 先相遇找点，再头遇找口 |
| 回文链表 | 找中点 → 反转后半 → 比较 |
| 删倒数第 N | dummy + fast 先走 N + 一起走 |
| 单调栈 | 遇到更大的就弹，存下标算距离 |
| 循环数组 | `i%n` 取模 + `i<n` 只入一次 |
| 接雨水 | 栈顶凹槽 + 左右边界算宽高 |
| 找边界二分 | `lower_bound` 两次，右边界 = lower(t+1)-1 |
| 旋转二分 | 判 mid 段位，再判 target 方向 |
| 二分答案 | `while(left<right)` 猜 k，验证可行 |
| 层序遍历 | queue + 先记 size + for i<size |
| BST 验证 | 范围递归 (LONG_MIN,LONG_MAX) 或中序递增 |
| 构造二叉树 | pre 首根 + in_map 分界 + pre_idx 传引用 |
| LCA | 后序找 p/q，左右各一个就是 root |
| 路径和 III | 树上跑前缀和 + map 查 need + 回溯 |
| 直径 | 后序返高度 + 全局 max(L+R) |
| 岛屿数量 | 遇 `1` 计数 + 四向淹成 `0` |
| 课程表 | 三色 DFS：白→灰→黑，遇灰即环 |
| 被围绕区域 | 边界 DFS 标记 T → 内 O→X → T→O 还原 |
| 烂橘子 | 多源入队 + fresh 计数 + size 分层 |
| 01 矩阵 | 多源入队 + INT_MAX 标记 + 同步扩散 |
| 全排列 | used 标记 + 满叶子收集 |
| 组合总和 | 排序 + start+i(可重复) + break 剪枝 |
| 单词搜索 | 四向 DFS + `#` 标记 + 回溯恢复 |
