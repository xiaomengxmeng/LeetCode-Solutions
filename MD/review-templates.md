# 🧠 答题技巧模板 — 抽象通用版

> 按**技巧体系**组织，每个模板是**一类题的通用骨架**
> 对照具体题目看 → 见每日记录

---

# 一、哈希表（配对查找）

**什么时候用？**
- 需要 O(1) 查找配对元素
- "两数之和 / 是否存在互补数 / 分组归类"
- 需要记录"已出现过的某个值及其位置"

**通用模板：一遍扫描 + 查表**
```
遍历每个元素：
    计算需要的配对值 complement = target - current
    如果 complement 已在表中 → 找到配对，直接返回
    否则将当前元素及其索引（或其他信息）存入表
```

```cpp
// 核心骨架
for (auto& x : nums) {
    need = target - x;
    if (map.count(need)) return answer;
    map[x] = /* 相关值 */;
}
```

**变体**：
- 存下标 → 返回位置（如 Two Sum）
- 存计数 → 统计频率（如 Valid Anagram）
- 存分组 key → 同类归组（如 Group Anagrams）

**易错**：先查后存，避免自己匹配自己

---

# 二、滑动窗口（子串/子数组）

**什么时候用？**
- "最长/最短子串 / 子数组"
- "包含/不包含某些字符的连续区间"
- 要求 **连续** 且 **区间可变**

**通用模板：右边界扩张 → 左边界收缩 → 更新答案**
```
右边界 right 逐步右移：
    将 s[right] 纳入窗口，更新窗口状态
    当窗口不满足条件时，右移 left 收缩窗口
    此时窗口满足条件，更新最优解
```

```cpp
int left = 0, ans = 0;
for (int right = 0; right < n; right++) {
    add(s[right]);                          // 右边界入窗
    while (!valid()) remove(s[left++]);     // 不满足时左缩
    ans = max(ans, right - left + 1);       // 更新最优解
}
```

**两个关键判断**：
| 区别 | 变长窗口 | 固定窗口 |
|:----|:--------|:--------|
| 收缩条件 | 窗口内不满足约束 | right >= 窗口大小 |
| 示例 | 最长无重复子串 | 字符串异位词 |
| 左边界更新 | while 收缩 | 同步移动 |

**易错**：
- `while` 不是 `if`：可能一次需要收缩多个字符
- 频率数组 `freq[128]` 覆盖 ASCII，`freq[26]` 仅字母
- 更新答案的位置：收缩后（窗口有效时）

---

# 三、双指针（原地处理 / 间隔控制）

**什么时候用？**
- 需要原地修改数组（快慢指针）
- 需要合并、分割（排序后左右夹逼）
- 链表中间、倒数第 N 个等定位问题（快慢间隔）

## 3.1 快慢指针 · 原地修改

**核心思想**：一个指针遍历（读），一个指针记录（写），一快一慢

```
slow 指向要写入的位置
fast 遍历每个元素：
    如果元素满足保留条件 → 复制到 slow，slow++
如果末尾需要填充 → 从 slow 开始填充
```

```cpp
int slow = 0;
for (int fast = 0; fast < n; fast++) {
    if (shouldKeep(nums[fast])) {
        nums[slow++] = nums[fast];
    }
}
// 可选尾部填充
while (slow < n) nums[slow++] = defaultValue;
```

## 3.2 快慢指针 · 间隔定位（链表）

**核心思想**：一个先走 k 步，然后同步前进，利用相对距离定位

```
fast 先走 n 步
然后 fast 和 slow 同步走
当 fast 到末尾时，slow 就在目标位置
```

```cpp
ListNode *slow = dummy, *fast = dummy;
for (int i = 0; i < n; i++) fast = fast->next;
while (fast) {
    slow = slow->next;
    fast = fast->next;
}
// slow 在目标位置
```

## 3.3 左右夹逼（有序数组）

**核心思想**：排序后 left + right 从两端向中间靠拢

```cpp
sort(nums.begin(), nums.end());
int left = 0, right = n - 1;
while (left < right) {
    int sum = nums[left] + nums[right];
    if (sum == target) return true;
    if (sum < target) left++;
    else right--;
}
```

**变体速查**：
| 场景 | slow 含义 | fast 含义 | 特点 |
|:----|:---------|:---------|:-----|
| 原地去重 | 待写入位置 | 遍历指针 | 相邻重复跳过 |
| 移动零 | 非零位置 | 遍历指针 | 末尾补零 |
| 移除元素 | 有效位置 | 遍历指针 | 符合条件的才保留 |
| 链表定位 | 前驱/目标 | 探路指针 | 先走间隔 |

---

# 四、链表操作

**什么时候用？**
- 需要反转、合并、删除节点
- 需要检测环、找交点
- 题目给的是单链表 ListNode 结构

## 4.1 反转

**核心思想**：三指针，先保存后继再反转指向

```
prev = null, cur = head
while cur 不为空：
    保存 cur->next
    将 cur->next 指向 prev
    prev 前移，cur 前移
返回 prev
```

```cpp
ListNode* prev = nullptr, *cur = head;
while (cur) {
    ListNode* nxt = cur->next;
    cur->next = prev;
    prev = cur;
    cur = nxt;
}
return prev;  // 新头
```

## 4.2 快慢指针检测环、找中点

**核心思想**：快走 2、慢走 1 → 相遇则有环 / 慢到中点

```cpp
while (fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;
    // slow 到中点 / 相遇则跳出
}
```

- 环入口：相遇后，头指针和慢指针同步走，相遇处即入口
- 中点：slow 在中点（奇数个），或前一半末尾（偶数个）

## 4.3 虚拟头节点（dummy）

**什么时候用？** 头节点可能被删除、交换、修改

```cpp
ListNode* dummy = new ListNode(0, head);
// 操作 dummy->next...
return dummy->next;
```

**链表易错三原则**：
1. 改指向前先保存 next
2. 头可能变 → 用 dummy
3. while 条件 `fast && fast->next`（`&&` 不是 `||`）

---

# 五、单调栈（下一个更大/更小元素）

**什么时候用？**
- "下一个更大元素 / 上一个更小元素"
- 找右侧/左侧第一个比自己大（小）的元素
- 通常会有一个"等待匹配"的序列

**核心思想**：维护栈内元素有序；遇到破坏顺序的元素时，不断弹出"处理"它们

**通用模板：单调递减栈（找下一个更大）**
```
遍历每个元素：
    while 栈不空 && 当前元素 > 栈顶：
        弹出栈顶 → 栈顶的答案就是当前元素
    当前元素入栈
```

```cpp
stack<int> st;  // 存下标
vector<int> res(n, defaultValue);
for (int i = 0; i < n; i++) {
    while (!st.empty() && needPop(st.top(), i)) {
        int top = st.top(); st.pop();
        res[top] = i - top;  // 或赋值当前值
    }
    st.push(i);
}
```

**单调栈方向判断**：
| 条件 | 栈的单调性 | 找什么 |
|:----|:---------|:-------|
| `arr[st.top()] < arr[i]` 弹 | 递减（栈底→栈顶） | 下一个更大 |
| `arr[st.top()] > arr[i]` 弹 | 递增（栈底→栈顶） | 下一个更小 |

**三个变体**：
- 普通：遍历一次，答案 = 当前值
- 循环数组：`i % n` 遍历 2n 次，`if (i < n)` 才入栈
- 接雨水：`st.empty()` 时 break（无左边界），按行 `宽度 × 高度`

```
接雨水特殊操作：
    bottom = 弹出栈顶（凹槽底部）
    if (栈空) break                   // 无左边界
    宽度 = i - 新栈顶 - 1
    高度 = min(左柱高, 右柱高) - 底部
    累加 宽度 × 高度
```

---

# 六、二分查找

**什么时候用？**
- 有序数组中查找
- 找边界（第一个/最后一个满足条件的位置）
- 猜一个答案，验证可行性（二分答案）

## 6.1 标准二分（找精确值）

```cpp
int left = 0, right = n - 1;
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) return mid;
    if (nums[mid] < target) left = mid + 1;
    else right = mid - 1;
}
return -1;
```

## 6.2 lower_bound（找第一个 >= target 的位置）

**核心思想**：缩减右边界时用 `>=`，保证 left 最终指向"第一个满足条件"的位置

```cpp
int lower_bound(vector<int>& nums, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) right = mid - 1;
        else left = mid + 1;
    }
    return left;
}
```
- 找右边界 → `lower_bound(target+1) - 1`
- 找插入位置 → `lower_bound(target)` 直接返回

## 6.3 旋转数组二分

**核心思想**：先判断 mid 落在左段还是右段，再判断 target 在段的哪一侧

```
if nums[0] <= nums[mid]:    // mid 在左段（旋转点右边）
    target 在 [nums[0], nums[mid]) → 左半
    否则 → 右半
else:                       // mid 在右段
    target 在 (nums[mid], nums[back]] → 右半
    否则 → 左半
```

## 6.4 二分答案

**什么时候用？** "最大化最小值 / 最小化最大值 / xx 是否可行"

**核心思想**：答案有单调性（如果 k 可行，则 k+1 也可行），二分猜答案

```cpp
int left = minVal, right = maxVal;
while (left < right) {
    int mid = left + (right - left) / 2;
    if (check(mid)) right = mid;    // mid 可行，试更小的
    else left = mid + 1;            // 不可行，只能更大
}
return left;
```

**二分循环条件速查**：
| 场景 | 循环条件 | left 更新 | right 更新 | 返回值 |
|:----|:--------|:---------|:---------|:------|
| 精确查找 | `left <= right` | `mid + 1` | `mid - 1` | `mid` / `-1` |
| lower_bound | `left <= right` | `mid + 1` | `mid - 1` | `left` |
| 二分答案·可行 | `left < right` | `mid + 1` | `mid` | `left` |
| 二分答案·不可行 | `left < right` | `mid + 1` | `mid` | `left` |

**易错**：
- `mid = left + (right - left) / 2` 防溢出
- 二分答案中 `right = mid`（不是 `mid-1`，因 mid 本身可能是答案）

---

# 七、二叉树遍历

**什么时候用？**
- 树的结构性处理：遍历、比较、构造
- 递归三板斧：终止条件 + 递归逻辑 + 返回值

## 7.1 BFS 层序遍历

**核心思想**：队列 + 按层处理（先记录 size）

```cpp
queue<TreeNode*> q;
q.push(root);
while (!q.empty()) {
    int size = q.size();          // 先记录当前层大小
    for (int i = 0; i < size; i++) {
        处理当前节点
        孩子入队
    }
}
```

**适用**：层序、最小深度、右视图

## 7.2 递归遍历

| 遍历 | 递归顺序 | 迭代关键 |
|:----|:--------|:---------|
| 前序 | 根 → 左 → 右 | 根先入，右左入栈 |
| 中序 | 左 → 根 → 右 | 一路向左，出栈后走右 |
| 后序 | 左 → 右 → 根 | 前序变体 + reverse |

**中序迭代模板**（BST 必用）：
```cpp
stack<TreeNode*> st;
TreeNode *cur = root, *prev = nullptr;
while (!st.empty() || cur) {
    while (cur) { st.push(cur); cur = cur->left; }  // 一路向左
    cur = st.top(); st.pop();
    // 处理 cur（此时 cur 是中序顺序）
    prev = cur;
    cur = cur->right;  // 转向右子树
}
```

## 7.3 BST 验证

- **范围法**：向下传递 `(lower, upper)` 区间，值超出即非法
- **中序法**：中序遍历结果必须严格递增

```cpp
// 范围骨架
if (val <= lower || val >= upper) return false;

// 中序骨架
if (prev && cur->val <= prev->val) return false;
```

## 7.4 递归构造二叉树

**核心思想**：前序/后序定根 → 中序分左右 → 哈希表加速

```
前序第一个 = 根
中序中，根的位置 → 左边是左子树，右边是右子树
递归构造
注意：索引必须传引用（全局递增）
```

---

# 八、回溯（排列/组合/搜索）

**什么时候用？**
- "所有可能的... / 所有组合 / 所有路径"
- 需要枚举所有决策路径的问题
- 核心：**选择 → 递归 → 撤销**

**通用模板框架**：
```
backtrack(状态参数):
    if 到达终点:
        记录结果
        return
    for 所有可能的下一步选择:
        if 选择非法: continue
        做选择（标记/加入）
        backtrack(更新后的状态)
        撤销选择（取消标记/弹出）
```

```cpp
void backtrack(..., vector<...>& path, vector<vector<...>>& res) {
    if (/* 终止条件 */) {
        res.push_back(path);
        return;
    }
    for (int i = /* 起始位置 */; i < n; i++) {
        if (/* 跳过条件 */) continue;
        // 做选择
        path.push_back(...);
        backtrack(..., path, res);
        path.pop_back();  // 撤销
    }
}
```

**三个核心维度决定了回溯变体**：

| 维度 | 问题类型 | 关键代码 |
|:----|:--------|:---------|
| **顺序是否重要？** | 排列(重要) vs 组合(不重要) | `used[]` 全遍历 vs `start` 不回头 |
| **元素能否重复？** | 不可重复 vs 可重复 | `i+1` vs `i` |
| **约束类型？** | 计数约束 vs 网格约束 | 加减计数 vs 方向数组 |

**四类回溯变体速查**：

| # | 典型题 | 防重复 | 下一层 | 剪枝 | 记录时机 |
|:-:|:------|:------|:------|:----|:--------|
| 1 | 全排列 | `used[i]` | 全遍历 | 无 | path 满时 |
| 2 | 子集 | `start` | `i+1` | 无 | 每层都记 |
| 3 | 组合总和 | `start` | `i`（可重复） | 排序 + `sum>target` break | sum==target |
| 4 | 单词搜索 | 原数组 `'#'` | 方向数组 | 字符不匹配 return | k==len-1 |

```
回溯三问：
① 下一层从哪开始？ → 全遍历(used) / start(组合) / i(可重复) / i+1(不重复)
② 什么时候记录？  → 叶子节点 / 每层都记 / 达到条件
③ 如何剪枝？      → 排序break / 不匹配return / 计数限制
```

---

# 九、图 DFS（网格 + 有向图）

**什么时候用？**
- 网格上的连通性问题（岛屿、边界、染色）
- 有向图的依赖检测（拓扑、环）
- "连通分量数量 / 能否到达 / 是否有环"

## 9.1 网格 DFS（水淹法）

**核心思想**：从某个格子出发，四方向扩散，将访问过的格子"淹没"（标记）

```cpp
void dfs(vector<vector<char>>& grid, int i, int j) {
    if (出界 || 已访问/不是目标) return;
    标记已访问（淹没/染色）;
    dfs(grid, i+1, j);
    dfs(grid, i-1, j);
    dfs(grid, i, j+1);
    dfs(grid, i, j-1);
}
```

**变体**：
| 场景 | 标记方式 | 额外操作 |
|:----|:--------|:---------|
| 计数（200） | 淹成 `'0'` | 遇到 `'1'` res++ 后 DFS |
| 求面积（695） | 淹成 `'0'` | DFS 返回面积累加 |
| 边界逆向（130） | 标为 `'T'` | 边界 DFS → 遍历替换 |
| 双边界（417） | 单独 bool 数组 | 太平洋/大西洋各一张表 |

## 9.2 三色 DFS（有向图环检测）

**什么时候用？** 需要检测有向图中的依赖环，bool visited 不够用

**核心思想**：0=未访问（白）→ 1=正在访问（灰）→ 2=已访问完（黑）

```
每节点初始 0（白）
DFS 进入时置 1（灰）
遍历邻居时：
    - 遇到 1（灰）→ 环！→ return false
    - 遇到 2（黑）→ 剪枝 → continue
DFS 退出时置 2（黑）
```

```cpp
vector<int> status(n, 0);  // 0=白, 1=灰, 2=黑

bool dfs(vector<vector<int>>& graph, vector<int>& status, int node) {
    if (status[node] == 1) return false;  // 环！
    if (status[node] == 2) return true;   // 剪枝
    status[node] = 1;
    for (int neighbor : graph[node])
        if (!dfs(graph, status, neighbor)) return false;
    status[node] = 2;
    return true;
}
```

**为什么需要三色？**
- bool visited 只有"没去过 / 去过了"两种状态
- 分不清"正在访问栈上"还是"已经确认无环"— 前者是环信号，后者是剪枝信号

---

# 十、多源 BFS（最短距离 / 逐层扩散）

**什么时候用？**
- 多个起点同时向外扩散
- 求每个位置到最近源的距离
- 所有源同时入队，一次 BFS 搞定

**核心思想**：所有源同时入队（距离 0），然后同步扩散。BFS 的天然性质：第一次到达 = 最短距离

```cpp
queue<pair<int,int>> q;
// 所有源入队
for () if (isSource) { q.push({i, j}); dist[i][j] = 0; }

while (!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    for (四个方向) {
        int nx = x + dx, ny = y + dy;
        if (在界内 && 未访问) {
            更新距离 = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
}
```

**是否需要分层？**（要不要 size 循环）

| 场景 | 分层？ | 原因 | 例 |
|:----|:------|:-----|:---|
| 按步数/轮次统计 | ✅ 需要 | 每层代表一个时间单位 | 烂橘子（分钟） |
| 仅逐个计算距离 | ❌ 不需要 | 每个格子独立存距离即可 | 01 矩阵 |

**多源 BFS vs 单源 BFS 的区别**：多源可以看作多加了一层"超级源点"连接到所有源，和所有源距离为 0

---

# 十一、树上特殊模式

## 11.1 后序遍历 + 全局变量

**什么时候用？** 需要在递归过程中收集"额外信息"，同时需要返回子树信息给父节点

```
返回值 = 子树信息（高度/深度/单边值）
全局变量 = 在每层收集的答案
后序更新全局：L 和 R 都已算好，可以组合起来
```

```cpp
int ans = 0;
int dfs(TreeNode* root, int& ans) {
    if (!root) return 0;
    int L = dfs(root->left, ans);
    int R = dfs(root->right, ans);
    ans = max(ans, /* L 和 R 的组合 */);
    return /* 单边信息 */ + 1;
}
```

**模式识别**：
- 543 直径：`ans = max(L + R)`，返回 `max(L,R)+1`
- 687 同值路径：加值判断，不相等就清零

## 11.2 树上前缀和 + 回溯

**什么时候用？** 树上找路径和，起点可以是任意节点，终点是后代节点

**核心思想**：把数组前缀和移植到树上，多了回溯

```
dfs(树, 当前前缀和):
    当前前缀和 += 当前节点值
    在 map 中查找 "当前前缀和 - target" 出现次数 → 即路径数
    将当前前缀和加入 map
    dfs(左)
    dfs(右)
    map 中移除当前前缀和（回溯！）
```

```cpp
void dfs(TreeNode* root, long long curr, int target,
         unordered_map<long long, int>& map, int& count) {
    if (!root) return;
    curr += root->val;
    count += map[curr - target];   // 关键：查之前出现过的前缀和
    map[curr]++;                   // 当前前缀和入 map
    dfs(root->left, curr, target, map, count);
    dfs(root->right, curr, target, map, count);
    map[curr]--;                   // 回溯！
}
```

**关键**：`map[0] = 1` 初始化、long long 防溢出、回溯恢复

## 11.3 LCA（后序查找）

**什么时候用？** 找两个节点的最近公共祖先

**核心思想**：后序遍历，左右子树各找一次；如果左找到 p/q、右也找到 p/q → 当前就是 LCA

```cpp
if (!root || root == p || root == q) return root;
auto left  = dfs(root->left, p, q);
auto right = dfs(root->right, p, q);
if (!left) return right;   // 全在右
if (!right) return left;   // 全在左
return root;               // 分居两侧
```

---

# 附：技巧选择流程

```
拿到题目 → 按以下顺序判断：

1. 数据结构类型？
   数组/字符串 → 2
   链表 → 4. 链表操作
   树 → 7. 二叉树 / 11. 树上特殊模式
   图/网格 → 9. 图 DFS / 10. 多源 BFS

2. 数组/字符串的具体要求？
   找配对/互补 → 1. 哈希表
   连续子串/子数组 → 2. 滑动窗口
   原地修改/去重/排序 → 3. 双指针
   找特定值/边界 → 6. 二分查找
   下一个更大/更小 → 5. 单调栈
   所有排列/组合/路径 → 8. 回溯

3. 链表的具体操作？
   反转 → 4.1 三指针
   环/中点 → 4.2 快慢
   删除/修改头 → 4.3 dummy
   回文比较 → 中点 + 反转 + 比较

4. 树的类型？
   遍历/层序 → 7.1/7.2
   BST 验证 → 7.3
   构造 → 7.4
   LCA → 11.3
   路径和(任意起点) → 11.2
   直径/同值路径 → 11.1

5. 图/网格的类型？
   连通分量/淹没 → 9.1 网格 DFS
   依赖/有向环 → 9.2 三色 DFS
   最短扩散 → 10. 多源 BFS
```
