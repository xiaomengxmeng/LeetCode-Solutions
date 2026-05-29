# 📊 学习总结

---

# 📊 第一周学习总结 (2026-04-13 ~ 2026-04-17)

## 📈 学习统计

| 指标 | 数值 |
|------|------|
| 总题目数 | 16 道 |
| Easy | 10 道 |
| Medium | 6 道 |
| 学习天数 | 5 天 |

---

## 📅 每日完成情况

| 日期 | 完成题目 | 核心技巧 |
|------|----------|----------|
| 04-13 | Two Sum, Check Strings, Group Anagrams | 哈希表、字符串处理 |
| 04-14 | Valid Parentheses, Min Stack, Valid Anagram, Plus One | 栈、频率统计、进位处理 |
| 04-15 | Merge Intervals, Add Binary, Add Strings, Find Anagrams | 区间合并、进位处理、滑动窗口 |
| 04-16 | Longest Substring, Permutation in String | 滑动窗口（固定/变长） |
| 04-17 | Move Zeroes, Remove Element, Reverse Linked List | 快慢指针、链表操作 |

---

## 🎯 核心技巧体系

### 1️⃣ 哈希表 (Hash Table)

**核心思想**：O(1) 查找，空间换时间

| 题目 | 应用场景 |
|------|----------|
| Two Sum (1) | 查找配对元素 |
| Group Anagrams (49) | 分组归类 |

**模板代码**：
```cpp
unordered_map<int, int> map;
map[key] = value;      // 插入
map.count(key)         // 查找
```

---

### 2️⃣ 栈 (Stack)

**核心思想**：LIFO，处理嵌套结构

| 题目 | 应用场景 |
|------|----------|
| Valid Parentheses (20) | 括号匹配 |
| Min Stack (155) | 辅助栈跟踪最小值 |

**模板代码**：
```cpp
stack<int> st;
st.push(x);    // 入栈
st.pop();      // 出栈
st.top();      // 访问栈顶（先检查 empty()）
```

---

### 3️⃣ 频率统计 (Frequency Count)

**核心思想**：固定大小数组统计字符出现次数

| 题目 | 应用场景 |
|------|----------|
| Valid Anagram (242) | 判断异位词 |
| Find Anagrams (438) | 滑动窗口 + 频率统计 |

**模板代码**：
```cpp
vector<int> count(26, 0);
count[c - 'a']++;   // 统计
count[c - 'a']--;   // 抵消
```

---

### 4️⃣ 进位处理 (Carry Processing)

**核心思想**：从低位到高位，`carry = sum / base`

| 题目 | 进制 |
|------|------|
| Plus One (66) | 十进制（只加1） |
| Add Binary (67) | 二进制 |
| Add Strings (415) | 十进制 |

**模板代码**：
```cpp
while (i >= 0 || j >= 0 || carry) {
    int sum = carry;
    if (i >= 0) sum += a[i--] - '0';
    if (j >= 0) sum += b[j--] - '0';
    carry = sum / base;        // 进位
    res += to_string(sum % base);  // 当前位
}
reverse(res.begin(), res.end());
```

---

### 5️⃣ 区间问题 (Interval)

**核心思想**：排序 → 遍历 → 合并

| 题目 | 应用场景 |
|------|----------|
| Merge Intervals (56) | 合并重叠区间 |

**模板代码**：
```cpp
sort(intervals.begin(), intervals.end());
res.push_back(intervals[0]);
for (int i = 1; i < intervals.size(); i++) {
    if (res.back()[1] >= intervals[i][0]) {
        res.back()[1] = max(res.back()[1], intervals[i][1]);
    } else {
        res.push_back(intervals[i]);
    }
}
```

---

### 6️⃣ 滑动窗口 (Sliding Window)

**核心思想**：窗口滑动 + 增量更新

| 类型 | 题目 | 特点 |
|------|------|------|
| 固定窗口 | Find Anagrams (438), Permutation (567) | 窗口大小固定 |
| 变长窗口 | Longest Substring (3) | 左边界可跳跃 |

**固定窗口模板**：
```cpp
for (int i = window_size; i < n; i++) {
    // 进入字符
    count[s[i]]--;
    if (count[s[i]] == 0) matched++;
    
    // 离开字符
    count[s[i - window_size]]++;
    if (count[s[i - window_size]] == 0) matched++;
}
```

**变长窗口模板**：
```cpp
int left = 0;
for (int i = 0; i < n; i++) {
    if (满足收缩条件) {
        left = 更新位置;  // 跳跃更新
    }
    maxLen = max(maxLen, i - left + 1);
}
```

---

### 7️⃣ 快慢指针 (Fast-Slow Pointers)

**核心思想**：一个遍历，一个记录位置

| 题目 | 应用场景 |
|------|----------|
| Move Zeroes (283) | 原地移动元素 |
| Remove Element (27) | 原地删除元素 |

**模板代码**：
```cpp
int slow = 0;
for (int fast = 0; fast < n; fast++) {
    if (满足条件) {
        nums[slow++] = nums[fast];
    }
}
// 如果需要，填充剩余位置
```

---

### 8️⃣ 链表操作 (Linked List)

**核心思想**：改变指针方向，注意保存 next

| 题目 | 应用场景 |
|------|----------|
| Reverse Linked List (206) | 反转链表 |

**模板代码**：
```cpp
ListNode* prev = nullptr;
ListNode* cur = head;
while (cur != nullptr) {
    ListNode* next = cur->next;  // 先保存
    cur->next = prev;            // 反转
    prev = cur;
    cur = next;
}
return prev;
```

---

## ⚠️ 易错点总结

| 类型 | 常见错误 | 正确做法 |
|------|----------|----------|
| 栈操作 | `top()` 前未检查 `empty()` | 先检查再访问 |
| 数组索引 | `size()` 当作最后索引 | 最后索引是 `size() - 1` |
| 滑动窗口 | 每次遍历计算 matched | 增量更新 |
| 链表操作 | 改变指针后丢失 next | 先保存 next |
| 循环条件 | 忘记包含 carry | `i>=0 \|\| j>=0 \|\| carry` |

---

## 💡 学习心得

1. **模式识别很重要**：看到"两数之和"→ 哈希表，看到"括号匹配"→ 栈
2. **增量更新是关键**：滑动窗口、频率统计都要避免重复计算
3. **边界条件要仔细**：空数组、空栈、空链表都要处理
4. **代码复用**：很多题目核心逻辑相同，只是细节不同

---

**第一周圆满完成！继续加油！** 🎉

---

# 📊 第二周学习总结 (2026-04-21 ~ 2026-04-23)

## 📈 学习统计

| 指标 | 数值 |
|------|------|
| 总题目数 | 11 道 |
| Easy | 7 道 |
| Medium | 4 道 |
| 学习天数 | 3 天 |

---

## 📅 每日完成情况

| 日期 | 完成题目 | 核心技巧 |
|------|----------|----------|
| 04-21 | Swap Nodes in Pairs, Linked List Cycle, Cycle II, Middle Node | 虚拟头节点、快慢指针 |
| 04-22 | Merge Two Lists, Remove Duplicates, Remove Elements, Palindrome | 虚拟头节点、找中点+反转 |
| 04-23 | Intersection, Remove Nth Node, Add Two Numbers | 双指针走两遍、快慢指针间隔 |

---

## 🎯 核心技巧体系

### 1️⃣ 快慢指针 (Fast-Slow Pointers) ⭐ 核心技巧

**核心思想**：快指针走2步，慢指针走1步

| 应用场景 | 题目 | 循环条件 |
|----------|------|----------|
| 检测环 | [141] Linked List Cycle | `fast && fast->next` |
| 找环入口 | [142] Linked List Cycle II | 两阶段法 |
| 找中点 | [876] Middle of the Linked List | `fast && fast->next` |
| 找倒数第N个 | [19] Remove Nth Node | 快指针先走n步 |

**模板代码**：
```cpp
ListNode *slow = head, *fast = head;
while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
}
// slow 即为中点
```

**两阶段法找环入口**：
```cpp
// 阶段1：找相遇点
while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) break;
}
if (!fast || !fast->next) return nullptr;

// 阶段2：找入口
ListNode *p1 = head, *p2 = slow;
while (p1 != p2) {
    p1 = p1->next;
    p2 = p2->next;
}
return p1;
```

---

### 2️⃣ 虚拟头节点 (Dummy Head)

**核心思想**：统一处理头节点边界情况

| 场景 | 题目 | 原因 |
|------|------|------|
| 头节点可能被删除 | [203] Remove Elements | 需要保护头节点 |
| 头节点需要交换 | [24] Swap Nodes in Pairs | 第一个节点需要前驱 |
| 构建新链表 | [21] Merge Two Lists, [2] Add Two Numbers | 统一连接逻辑 |

**判断是否需要虚拟头节点**：
- 头节点会被删除/修改？ → **需要**
- 头节点不会被删除？ → **不需要**

**模板代码**：
```cpp
ListNode *dummy = new ListNode(0, head);
ListNode *cur = dummy;
// ... 操作
return dummy->next;
```

---

### 3️⃣ 链表反转 (Reverse Linked List)

**核心思想**：三指针反转，先保存 next

| 题目 | 应用场景 |
|------|----------|
| [206] Reverse Linked List | 完整反转 |
| [234] Palindrome | 反转后半部分 |

**模板代码**：
```cpp
ListNode *prev = nullptr, *cur = head;
while (cur) {
    ListNode *next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
}
return prev;
```

---

### 4️⃣ 双指针走两遍 (Two Pointers Walk Twice)

**核心思想**：消除长度差异

| 题目 | 应用场景 |
|------|----------|
| [160] Intersection | 找相交点 |

**原理**：
```
pA: 链表A → 链表B，走 a + b + c 步
pB: 链表B → 链表A，走 a + c + b 步
步数相等，必在相交点相遇！
```

**模板代码**：
```cpp
ListNode *pa = headA, *pb = headB;
while (pa != pb) {
    pa = pa ? pa->next : headB;
    pb = pb ? pb->next : headA;
}
return pa;
```

---

### 5️⃣ 逐位相加 + 进位 (Add with Carry)

**核心思想**：模拟手动加法

| 题目 | 应用场景 |
|------|----------|
| [2] Add Two Numbers | 链表相加 |

**模板代码**：
```cpp
int carry = 0;
ListNode *dummy = new ListNode(0), *tail = dummy;

while (l1 || l2 || carry) {
    int val1 = l1 ? l1->val : 0;
    int val2 = l2 ? l2->val : 0;
    int sum = val1 + val2 + carry;
    
    carry = sum / 10;
    tail->next = new ListNode(sum % 10);
    tail = tail->next;
    
    l1 = l1 ? l1->next : nullptr;
    l2 = l2 ? l2->next : nullptr;
}
return dummy->next;
```

---

## ⚠️ 易错点总结

| 类型 | 常见错误 | 正确做法 |
|------|----------|----------|
| 快慢指针 | 循环条件用 `\|\|` | 用 `&&` |
| 虚拟头节点 | 忘记使用 | 头节点可能被删除时必须用 |
| 删除节点 | cur 指向 head | cur 应指向 dummy 或前驱 |
| 链表连接 | `dummy->next = node` 覆盖 | 用 tail 指针跟踪 |
| 空指针 | 直接访问 `l1->val` | `l1 ? l1->val : 0` |
| 指针移动 | 相等时移动 cur | 删除时 cur 不移动 |

---

## 📊 两周对比

| 维度 | Week 1 | Week 2 |
|------|--------|--------|
| 题目数 | 16 道 | 11 道 |
| Easy | 10 道 | 7 道 |
| Medium | 6 道 | 4 道 |
| 核心技巧 | 8 种 | 5 种（链表专题） |
| 重点 | 数组、字符串、滑动窗口 | 链表、快慢指针 |

---

## 📚 下周计划

根据学习路径，第3周应该学习：

| 主题 | 重点题目 | 核心技能 |
|------|----------|----------|
| 栈进阶 | Valid Parentheses, Next Greater Element | 单调栈 |
| 队列应用 | Implement Queue using Stacks | 队列实现 |
| 复习巩固 | 重做链表错题 | 检验知识内化 |

---

## 💡 学习心得

1. **快慢指针是链表神器**：检测环、找中点、找倒数第N个，一套模板搞定
2. **虚拟头节点判断**：头节点可能被删除 → 需要
3. **先保存再修改**：链表操作的核心原则
4. **综合题检验掌握程度**：[234] 回文链表 = 找中点 + 反转 + 比较

---

**第二周圆满完成！链表技巧已掌握！** 🎉

---

# 📊 第三周学习总结 (2026-04-27 ~ 2026-04-30)

## 📈 学习统计

| 指标 | 数值 |
|------|------|
| 总题目数 | 6 道 |
| Easy | 2 道 |
| Medium | 3 道 |
| **Hard** | **1 道** 🎉 |
| 学习天数 | 4 天 |

---

## 📅 每日完成情况

| 日期 | 完成题目 | 核心技巧 |
|------|----------|----------|
| 04-27 | Implement Queue using Stacks, Implement Stack using Queues | 栈队列互转 |
| 04-28 | Next Greater Element I, Daily Temperatures | 单调栈入门 |
| 04-29 | Next Greater Element II | 循环数组单调栈 |
| 04-30 | **Trapping Rain Water** | 单调栈按行计算 |

---

## 🎯 核心技巧体系

### 1️⃣ 单调栈 (Monotonic Stack) ⭐ 本周核心

**核心思想**：栈内元素保持单调性，用于找"下一个更大/更小元素"

| 类型 | 栈内顺序 | 适用场景 |
|------|----------|----------|
| 单调递减栈 | 栈底→栈顶：大→小 | 找下一个更大元素 |
| 单调递增栈 | 栈底→栈顶：小→大 | 找下一个更小元素 |

**单调栈系列题目**：

| 题号 | 题目 | 难度 | 栈存什么 | 关键点 |
|------|------|------|----------|--------|
| 496 | Next Greater Element I | Easy | 元素值 | 预处理 + map 查表 |
| 739 | Daily Temperatures | Medium | 下标 | 计算天数差 |
| 503 | Next Greater Element II | Medium | 下标 | 循环数组，只入栈一次 |
| 42 | Trapping Rain Water | **Hard** | 下标 | 按行计算，min(左,右) |

**通用模板**：
```cpp
stack<int> st;
for (int i = 0; i < n; i++) {
    while (!st.empty() && 满足条件) {
        int top = st.top();
        st.pop();
        // 处理答案
    }
    st.push(i);  // 或 push(元素值)
}
```

---

### 2️⃣ 栈队列互转

**核心思想**：利用数据结构的特性差异

| 题目 | 方法 | 复杂度 |
|------|------|--------|
| [232] 栈实现队列 | 双栈：入队栈 + 出队栈 | 均摊 O(1) |
| [225] 队列实现栈 | 单队列：push 时重排 | push O(n), pop O(1) |

**关键对比**：
- 栈倒栈 → 顺序反转
- 队列倒队列 → 顺序不变

---

### 3️⃣ 循环数组处理

**核心思想**：用 `i % n` 取模模拟循环

```cpp
for (int i = 0; i < n * 2; i++) {
    int idx = i % n;  // 真实下标
    // ...
    if (i < n) st.push(i);  // 只在第一圈入栈
}
```

---

### 4️⃣ 接雨水（按行计算）

**核心思想**：单调递增栈，栈顶是凹槽底部

```
水量 = 宽度 × 高度
宽度 = 右边界 - 左边界 - 1
高度 = min(左边界高度, 右边界高度) - 底部高度
```

---

## ⚠️ 易错点总结

| 类型 | 常见错误 | 正确做法 |
|------|----------|----------|
| 单调栈 | 存元素值但需要位置信息 | 存下标 |
| 循环数组 | 第二圈也入栈 | `if (i < n)` 只入栈一次 |
| 接雨水 | 水高度只用右边界 | `min(左, 右) - 底部` |
| map 访问 | `map(key)` 语法错误 | `map[key]` 或 `map.count(key)` |

---

## 🏆 里程碑达成

- [x] **Hard 题突破**：从 0 到 1！完成 42. Trapping Rain Water
- [x] **单调栈掌握**：从入门到精通，4 道题循序渐进

---

## 📊 三周对比

| 维度 | Week 1 | Week 2 | Week 3 |
|------|--------|--------|--------|
| 题目数 | 16 道 | 11 道 | 6 道 |
| Easy | 10 道 | 7 道 | 2 道 |
| Medium | 6 道 | 4 道 | 3 道 |
| Hard | 0 道 | 0 道 | **1 道** |
| 核心技巧 | 8 种 | 5 种 | 4 种（单调栈专题） |
| 重点 | 数组、字符串、滑动窗口 | 链表、快慢指针 | 单调栈 |

---

## 📚 下周计划

根据学习路径，第4周应该学习：

| 主题 | 重点题目 | 核心技能 |
|------|----------|----------|
| 二叉树基础 | Max Depth, Same Tree | DFS/BFS、递归 |
| 二叉树遍历 | Inorder, Preorder, Postorder | 递归转迭代 |
| 层序遍历 | Level Order | BFS |

---

## 💡 学习心得

1. **单调栈是找"下一个更大元素"的神器**：一个模板解决多道题
2. **存下标还是存值**：需要位置信息 → 存下标；只需要元素值 → 存值
3. **Hard 题也是基础技巧的组合**：接雨水 = 单调栈 + min(左,右)
4. **循序渐进很重要**：从 Easy 到 Medium 到 Hard，每一步都算数

---

**第三周圆满完成！Hard 题突破！单调栈掌握！** 🎉

---

# 📊 第四周学习总结 (2026-05-06 ~ 2026-05-09)

## 📈 学习统计

| 指标 | 数值 |
|------|------|
| 总题目数 | 8 道 |
| Easy | 7 道 |
| Medium | 1 道 |
| 学习天数 | 4 天 |

---

## 📅 每日完成情况

| 日期 | 完成题目 | 核心技巧 |
|------|----------|----------|
| 05-06 | Maximum Depth, Same Tree | DFS递归、同时遍历 |
| 05-07 | Symmetric Tree, Invert Tree, Level Order | 镜像比较、BFS层序 |
| 05-08 | Minimum Depth | BFS找最短路径 |
| 05-09 | Balanced Tree, Path Sum | 自底向上递归、递归减值 |

---

## 🎯 核心技巧体系

### 1️⃣ 二叉树递归 (Binary Tree Recursion) ⭐ 本周核心

**核心思想**：递归 = 终止条件 + 递归逻辑 + 返回值

| 题目 | 递归逻辑 | 终止条件 |
|------|----------|----------|
| [104] Max Depth | `max(left, right) + 1` | `root == nullptr` |
| [100] Same Tree | `left && right` | 结构或值不同 |
| [101] Symmetric | `mirror(left, right)` | 不对称 |
| [226] Invert | `swap(left, right)` | `root == nullptr` |
| [112] Path Sum | `targetSum -= val` | 叶子节点且和为0 |

**通用模板**：
```cpp
TreeNode* dfs(TreeNode* root) {
    if (!root) return nullptr;  // 终止条件
    // 递归逻辑
    TreeNode* left = dfs(root->left);
    TreeNode* right = dfs(root->right);
    // 返回值处理
    return result;
}
```

---

### 2️⃣ 自底向上递归 (Bottom-Up Recursion)

**核心思想**：先递归到底，再向上返回结果

| 题目 | 应用场景 |
|------|----------|
| [110] Balanced Tree | 用 -1 标记不平衡 |

**关键代码**：
```cpp
int getHeight(TreeNode* root) {
    if (!root) return 0;
    int left = getHeight(root->left);
    if (left == -1) return -1;  // 提前返回
    int right = getHeight(root->right);
    if (right == -1 || abs(left - right) > 1)
        return -1;
    return max(left, right) + 1;
}
```

---

### 3️⃣ BFS 层序遍历 (Level Order Traversal)

**核心思想**：队列 + 按层处理

| 题目 | 应用场景 |
|------|----------|
| [102] Level Order | 收集每层节点 |
| [111] Min Depth | 找第一个叶子节点 |

**模板代码**：
```cpp
queue<TreeNode*> q;
q.push(root);
while (!q.empty()) {
    int size = q.size();  // 当前层节点数
    for (int i = 0; i < size; i++) {
        TreeNode* node = q.front(); q.pop();
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}
```

---

### 4️⃣ 镜像比较 (Mirror Comparison)

**核心思想**：左子树的左 vs 右子树的右

| 题目 | 应用场景 |
|------|----------|
| [101] Symmetric Tree | 判断对称 |

**关键代码**：
```cpp
bool mirror(TreeNode* left, TreeNode* right) {
    if (!left && !right) return true;
    if (!left || !right) return false;
    return left->val == right->val
        && mirror(left->left, right->right)
        && mirror(left->right, right->left);
}
```

---

## ⚠️ 易错点总结

| 类型 | 常见错误 | 正确做法 |
|------|----------|----------|
| 路径和 | 只检查 `targetSum == 0` | 必须同时检查是叶子节点 |
| 最小深度 | 只检查 `!root->left` | 必须同时检查 `!root->right` |
| 平衡树 | 直接用 `abs(left, right)` | 用 `abs(left - right)` |
| BFS | 每次处理一个节点 | 按层处理，先记录 `size` |
| 递归返回值 | 忘记返回 | 每条路径都要 return |

---

## 📊 四周对比

| 维度 | Week 1 | Week 2 | Week 3 | Week 4 |
|------|--------|--------|--------|--------|
| 题目数 | 16 道 | 11 道 | 6 道 | 8 道 |
| Easy | 10 道 | 7 道 | 2 道 | 7 道 |
| Medium | 6 道 | 4 道 | 3 道 | 1 道 |
| Hard | 0 道 | 0 道 | 1 道 | 0 道 |
| 核心技巧 | 8 种 | 5 种 | 4 种 | 4 种（二叉树专题） |
| 重点 | 数组、字符串 | 链表 | 单调栈 | 二叉树递归 |

---

## 📚 下周计划（见下方第四周进阶）

第四周进入二叉树进阶，学习遍历、构造、BST、路径等专题 → 见下方"第四周进阶"

---

## 💡 学习心得

1. **递归三要素**：终止条件 + 递归逻辑 + 返回值
2. **自底向上更高效**：平衡树用 -1 标记，避免重复计算
3. **BFS 找最短路径**：最小深度 = BFS 遇到第一个叶子节点
4. **镜像比较技巧**：对称问题 = 左子树的左 vs 右子树的右

---

**第四周圆满完成！二叉树基础掌握！** 🎉

---

# 📊 第四周进阶 (2026-05-10 ~ 2026-05-15)

## 📈 学习统计

| 指标 | 数值 |
|------|------|
| 总题目数 | 12 道（+ 复习2道） |
| Easy | 3 道 |
| Medium | 9 道 |
| 复习巩固 | 234 回文链表、20 有效括号 |
| 学习天数 | 5 天 |

---

## 📅 每日完成情况

| 日期 | 完成题目 | 核心技巧 |
|------|----------|----------|
| 05-10 | Preorder/Inorder/Postorder 遍历, Validate BST | 递归转迭代、中序递增 |
| 05-12 | Array to BST, Kth Smallest, LCA of BST | 二分构建、中序查第k、BST三向比较 |
| 05-13 | Construct Tree (Pre+In), Path Sum II | 前序定根+中序分左右、DFS回溯 |
| 05-14 | Path Sum III | 前缀和+哈希表+回溯 |
| 05-15 | Right Side View, LCA of BT | BFS/DFS双解、后序查找 |

---

## 🎯 核心技巧体系

### 1️⃣ 二叉树遍历三兄弟 (144/94/145)

| 遍历 | 递归 | 迭代思路 |
|:----:|:----|:---------|
| 前序 | 根→左→右 | 根先入，右再左入栈 |
| 中序 | 左→根→右 | 一路向左，出栈后走右 |
| 后序 | 左→右→根 | 前序变体：根→右→左，再 reverse |

**后序迭代口诀**：前序改右左右，最后 reverse 就是后序

---

### 2️⃣ 前序定根 + 中序分左右 (105)

```
preorder = [根, 左子树..., 右子树...]
inorder  = [左子树..., 根, 右子树...]
                  ↑ mid = in_map[根]
```

- **`pre_idx` 必须传引用**：全局递增，不能回溯
- **必须先构建左子树**：前序中左子树节点在右子树之前

---

### 3️⃣ 路径总和三部曲 (112/113/437)

| 题号 | 起点 | 终点 | 问法 | 方法 |
|:---:|:---:|:---:|:----|:----|
| 112 | 根 | 叶子 | 是否存在？ | 递归减值 |
| 113 | 根 | 叶子 | 列出所有路径 | DFS + 回溯 |
| 437 | **任意** | **任意后代** | 计数 | **前缀和 + 哈希表 + 回溯** |

**437 核心口诀**："当前前缀和 - targetSum = 之前出现过的前缀和 → 中间这段就是一条路径"
- `map[0] = 1` 处理根到当前节点整条路径
- 回溯 `map[curr_sum]--` 保证不同分支互不影响
- `long long` 防溢出

---

### 4️⃣ 二叉搜索树 (BST) 专题 (98/108/230/235)

| 题号 | 技巧 | 说明 |
|:---:|:----|:-----|
| 98 | 中序递增 | 中序遍历结果必递增 |
| 108 | 二分递归构建 | 中点做根，左半左子树，右半右子树 |
| 230 | 中序第k个 | 中序遍历到第k个 |
| 235 | 三向比较 | p,q都小→左，都大→右，分两侧→返回root |

---

### 5️⃣ 最近公共祖先 (LCA) (235/236)

| | 235 BST 版 | 236 普通树版 |
|:---:|:---------|:-----------|
| 思路 | 值大小三向比较 | 后序遍历查找 |
| 剪枝 | ✅ 单路递归 | ❌ 全量搜索 |
| 代码 | 5行 | 5行 |

**236 后序 LCA 口诀**："if (!left) return right; if (!right) return left; return root;"

---

### 6️⃣ BFS/DFS 双视角 (199)

- **BFS**：层序遍历，取每层最后一个 `i == size-1`
- **DFS**：先右后左，`depth == ans.size()` 取每层第一个

---

## ⚠️ 易错点总结

| 类型 | 常见错误 | 正确做法 |
|:----|:---------|:---------|
| 105 构造 | `pre_idx` 传值 | 必须传引用！ |
| 105 构造 | 先建右子树 | 必须先左后右（前序顺序决定） |
| 437 前缀和 | `curr_sum` 用 int | 用 `long long` 防溢出 |
| 437 前缀和 | map key 类型 int | map key 也要 `long long`，否则截断误触 map[0] |
| 437 前缀和 | 忘记 `map[0] = 1` | 根到当前节点路径为 targetSum 时漏统计 |
| 437 前缀和 | 忘记回溯 | `map[curr_sum]--` 恢复状态 |
| 迭代遍历 | while 条件用 `\|\|` | `while (!st.empty() \|\| cur)` 两个条件 |

---

## 📊 四周完整对比

| 维度 | W1 数组 | W2 链表 | W3 栈 | W4 二叉树 |
|:----:|:-------:|:-------:|:-----:|:---------:|
| 题目数 | 16 | 11 | 6 | **20** 🏆 |
| Easy | 10 | 7 | 2 | 10 |
| Medium | 6 | 4 | 3 | **10** 🏆 |
| Hard | 0 | 0 | 1 | 0 |
| 核心技巧 | 8种 | 5种 | 4种 | 10种 |
| 重点 | 哈希/窗口 | 快慢/虚拟头 | 单调栈 | 二叉树全覆盖 |

---

## 💡 学习心得

1. **二叉树是递归的最佳练习场**：从简单递归（104）到回溯（113）到前缀和（437），递归深度层层递进
2. **前序定根、中序分左右**：105 的核心思想可以迁移到 106（中序+后序）
3. **前缀和上树**：数组前缀和（560）移植到树（437）多了回溯，本质还是查表
4. **LCA 后序查找**：一个问题出左右子树的结果，是"分治"思想在树上的体现
5. **复习有价值**：一个月前做的 234 和 20 还能独立写出，说明已经内化
6. **53 道题达成** 🎉：从 0 到 53，覆盖了数组、链表、栈、二叉树四大数据结构

---

---

# 📊 第五周学习总结 (2026-05-18 ~ 2026-05-22)

## 📈 学习统计

| 指标 | 数值 |
|:----:|:----:|
| 总题目数 | **12 道** 🏆 |
| Easy | 1 道 |
| Medium | **11 道** |
| 学习天数 | 5 天 ✅ 全勤 |
| 复习巩固 | 206, 234, 19（链表三连复习） |

---

## 📅 每日完成情况

| 日期 | 完成题目 | 核心技巧 |
|:----:|:---------|:---------|
| 05-18 | Number of Islands, Clone Graph, Course Schedule | 网格DFS、哈希表深拷贝、三色DFS |
| 05-19 | Course Schedule II, Max Area of Island | DFS后序输出顺序、网格DFS面积累加 |
| 05-20 | Surrounded Regions, Pacific Atlantic, Rotting Oranges | 边界DFS逆向填充、双反向DFS、多源BFS |
| 05-21 | 01 Matrix, As Far from Land as Possible | 多源BFS最短距离、多源BFS分层计时 |
| 05-22 | Diameter of BT, Longest Univalue Path | 后序求高度+全局直径、值判断清零 |

---

## 🎯 核心技巧体系

### 1️⃣ 网格 DFS（水淹法）

**核心思想**：遇到陆地就 DFS 淹没，同时计数/标记

| 题号 | 题目 | 变体 |
|:---:|:----|:----|
| 200 | Number of Islands | 单纯计数，淹完即走 |
| 695 | Max Area of Island | DFS 返回面积累加 |
| 130 | Surrounded Regions | 边界 DFS 标记 → 逆向填充 |
| 417 | Pacific Atlantic Water Flow | 双边界 DFS → 取交集 |

**模板**：
```cpp
void dfs(vector<vector<int>>& grid, int i, int j) {
    if (出界 || 已访问/不是目标) return;
    标记已访问;
    dfs(grid, i+1, j);
    dfs(grid, i-1, j);
    dfs(grid, i, j+1);
    dfs(grid, i, j-1);
}
```

---

### 2️⃣ 图 DFS（三色法 + 拓扑排序）

**核心思想**：0=未访问, 1=正在访问, 2=已访问 — 检测环后序输出

| 题号 | 题目 | 关键 |
|:---:|:----|:----|
| 207 | Course Schedule | 三色 DFS 检测有向环 |
| 210 | Course Schedule II | DFS 后序输出 = 拓扑顺序 |
| 133 | Clone Graph | DFS + 哈希表映射新旧节点 |

---

### 3️⃣ 多源 BFS（全网扩散）

**核心思想**：所有源同时入队，逐层扩散，一次遍历解决最短距离

| 题号 | 题目 | 源 | 求什么 |
|:---:|:----|:-:|:------|
| 994 | Rotting Oranges | 烂橘子 | 全部腐烂需要几分钟 |
| 542 | 01 Matrix | 0 | 每个格子到最近0的距离 |
| 1162 | As Far from Land | 1（陆地） | 所有海洋中最远距离 |

**多源 BFS 用 `step` 分层模板**：
```cpp
queue<int> q;
// 所有源入队
while (!q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
        // 处理当前层
    }
    if (!q.empty()) step++;
}
```

---

### 4️⃣ 后序遍历 + 全局变量

**核心思想**：递归返回子树信息，用全局变量收集"额外"答案

| 题号 | 题目 | 返回值 | 全局变量 |
|:---:|:----|:------|:---------|
| 543 | Diameter of BT | 子树高度 | `ans = max(L+R)` |
| 687 | Longest Univalue Path | 同值路径长度 | `ans = max(L+R)` + 值判断 |

---

### 5️⃣ 链表复习收获

复习三连：206 反转链表 → 234 回文链表 → 19 删除倒数第 N 个

| 题号 | 核心技巧 | 一次过？ |
|:---:|:---------|:--------:|
| 206 | 三指针反转 | ❌ 第一次写成对交换，第二次改对 |
| 234 | 找中点 + 反转后半 | ✅ 一次过 |
| 19 | 快慢指针间隔 + dummy | ✅ 一次过 |

---

## ⚠️ 易错点总结

| 类型 | 常见错误 | 正确做法 |
|:----|:---------|:---------|
| 二维数组 res 初始化 | `res = (m, vector<int>(n, INF))` 变逗号表达式 | `res(m, vector<int>(n, INF))` 构造函数 |
| BFS step++ | 放 while 外或最后层多计 | `if (!q.empty()) step++` |
| 多源 BFS 源选择 | 每个 1 独立 BFS | 所有 0 同时入队，一次 BFS |
| 687 值判断 | 忘记检查孩子是否存在 | `root->left && root->left->val != root->val` 短路求值 |
| 图三色 DFS | 用 bool visited 无法检测环 | 用 0/1/2 三色 |

---

## 🏆 里程碑

- [x] **全勤 5 天**：连续学习，无断档 ✅
- [x] **图专题全覆盖**：网格 DFS、图 DFS 拓扑排序、多源 BFS
- [x] **Medium 11 道**：单周 Medium 题量新高 🏆
- [x] **多源 BFS 一条龙**：994 → 542 → 1162 一脉相承
- [x] **后序遍历模式定型**：110 → 236 → 543 → 687 同一套路
- [x] **链表复习验证**：206 需要再练，234 和 19 已掌握

---

## 📊 五周对比

| 维度 | W1 数组 | W2 链表 | W3 栈 | W4 二叉树 | **W5 图** |
|:----:|:-------:|:-------:|:-----:|:---------:|:---------:|
| 题目数 | 16 | 11 | 6 | 20 | **12** |
| Easy | 10 | 7 | 2 | 10 | **1** |
| Medium | 6 | 4 | 3 | 10 | **11** 🏆 |
| Hard | 0 | 0 | 1 | 0 | **0** |
| 核心技巧 | 8种 | 5种 | 4种 | 10种 | **5种**（图专题） |
| 重点 | 哈希/窗口 | 快慢/虚拟头 | 单调栈 | 二叉树 | **图 + 后序** |

---

## 💡 学习心得

1. **图题三板斧**：网格 DFS（水淹法）、图 DFS（三色法）、多源 BFS——覆盖了本周 80% 的题目
2. **多源 BFS 模板化**：所有源入队 + 分层处理，994/542/1162 一题比一题顺手
3. **后序遍历是万能框架**：求高度、求直径、求同值路径，都是在后序位置"顺便"做点事
4. **复习验证很有价值**：206 第一次还是写错了，说明确实不够熟，需要再练

---

## 📚 下周计划

| 主题 | 重点题目 | 核心技能 |
|:----|:---------|:---------|
| 核心算法 | 二分查找专题 | 标准二分、边界二分、答案二分 |
| 复习巩固 | 链表三连（206/234/19）再练 | 吃透反转链表 |

------

# 📊 第六周学习总结 (2026-05-25 ~ 2026-05-29)

## 📈 学习统计

| 指标 | 数值 |
|:----:|:----:|
| 总题目数 | **13 道** 🏆 |
| Easy | 0 道 |
| Medium | **13 道** |
| 学习天数 | 5 天 ✅ 全勤 |

---

## 📅 每日完成情况

| 日期 | 完成题目 | 核心技巧 |
|:----:|:---------|:---------|
| 05-25 | Binary Search, Search Insert Position, Find First and Last Position | 标准二分、lower_bound 两次 |
| 05-26 | Search in Rotated Sorted Array | 旋转数组分段二分 |
| 05-27 | Find Minimum in Rotated Array, Search 2D Matrix, Koko Eating Bananas | 旋转找极值、二维拉平、二分答案 |
| 05-28 | Permutations, Subsets, Combination Sum | 回溯三模板：used / start / 可重复 |
| 05-29 | Word Search, Generate Parentheses, Letter Combinations | 网格回溯、约束回溯、映射回溯 |

---

## 🎯 核心技巧体系

### 1️⃣ 二分查找五连 (704 / 35 / 34 / 33 / 153)

**核心思想**：每次缩小一半搜索范围，O(log n)

| 题号 | 题目 | 模板类型 | 返回值 |
|:---:|:----|:--------|:------|
| 704 | Binary Search | 标准二分 | `return mid` / `return -1` |
| 35 | Search Insert Position | 插入位置 | `return left` |
| 34 | Find First and Last Position | lower_bound 两次 | `{L, R-1}` |
| 33 | Search in Rotated Array | 先分段再判断 | `return mid` / `return -1` |
| 153 | Find Minimum in Rotated Array | while(left<right) | `return nums[left]` |

**四种二分模板一句话记**：
```
704 找到就返回，35 找不到返回 left
34 两次 lower_bound，33 分段判断方向
153 while(left<right)，一个条件找极值
```

### 2️⃣ 二分答案模式 (875)

**核心思想**：二分猜答案 + 验证函数判断可行性

```cpp
int left = 1, right = max(piles);
while (left < right) {
    int mid = left + (right - left) / 2;
    if (canEat(mid)) right = mid;
    else             left = mid + 1;
}
return left;
```

### 3️⃣ 二维矩阵二分 (74)

```cpp
// 拉平成一维，mid/n 做行，mid%n 做列
int m = matrix.size(), n = matrix[0].size();
int left = 0, right = m * n - 1;
```

### 4️⃣ 回溯三模板 ⭐ 本周核心

**统一框架**：
```cpp
void backtrack(状态参数) {
    if (满足条件) { 记录结果; return; }
    for (选择 in 所有可能的下一步) {
        if (选择无效) continue;
        做选择;
        backtrack(更新后的状态);
        撤销选择;
    }
}
```

| 题号 | 题目 | 防重复方式 | 记录时机 |
|:---:|:----|:---------|:--------|
| 46 | Permutations | used 数组 | path 满时 |
| 78 | Subsets | start + i+1 | 每层都记录 |
| 39 | Combination Sum | start + i（可重复）| sum==target |
| 79 | Word Search | 原数组标记 | k==len-1 |
| 22 | Generate Parentheses | left/right 计数 | left==right==0 |
| 17 | Letter Combinations | 映射 + 递进 | k==len |

**回溯题核心分类**：
```
是否需要回头？          排列(used) vs 子集(start)
元素能否重复使用？       组合(start+i) vs 组合总和(start+i)
是否有网格约束？         标准回溯 vs 网格回溯(方向数组)
是否有计数约束？         无约束 vs 括号计数(left/right)
```

---

## ⚠️ 易错点总结

### 二分篇
| 类型 | 常见错误 | 正确做法 |
|:----|:---------|:---------|
| right 初始值 | `right = nums.size()` | `right = nums.size() - 1` |
| lower_bound | `if >` 没加 `=` | `if (nums[mid] >= target)` |
| 旋转数组 | `nums[0] < nums[mid]` 漏等号 | `nums[0] <= nums[mid]` |
| 875 答案二分 | left 从 0 开始 | left 从 1 开始 |
| 153 找最小值 | `right = mid - 1` | `right = mid`（mid 本身可能是答案） |

### 回溯篇
| 类型 | 常见错误 | 正确做法 |
|:----|:---------|:---------|
| 78 子集 | `res.push(path)` 放在 for 里 | 放在 backtrack 开头 |
| 78 子集 | `backtrack(start+1)` | `backtrack(i+1)` |
| 39 组合 | `backtrack(start, ...)` 传 start | 传 i（可重复选） |
| 39 组合 | sum 累加不恢复 | 传值 `sum + candidates[i]` |
| 79 单词搜索 | `for (int i...)` 覆盖参数 | 用不同变量名 |
| 79 单词搜索 | 缺少边界检查 | 先检查 i,j 是否越界 |
| 17 电话号码 | `digits=""` 返回 `[""]` | 提前 `if (empty) return {}` |

---

## 🏆 里程碑

- [x] **全勤 5 天**：连续学习，无断档 ✅
- [x] **二分查找体系完整**：从标准二分到二分答案，7 道题全覆盖
- [x] **回溯模板打通**：从排列到组合到搜索，6 道题掌握四种变体
- [x] **周 Medium 题量新高**：13 道题全部 Medium 🏆
- [x] **总题数突破 78**：从 51 → 78 道，两周增长 27 道

---

## 📊 六周对比

| 维度 | W1 数组 | W2 链表 | W3 栈 | W4 二叉树 | W5 图 | **W6 二分+回溯** |
|:----:|:-------:|:-------:|:-----:|:---------:|:----:|:--------------:|
| 题目数 | 16 | 11 | 6 | 20 | 12 | **13** |
| Easy | 10 | 7 | 2 | 10 | 1 | **0** |
| Medium | 6 | 4 | 3 | 10 | 11 | **13** 🏆 |
| Hard | 0 | 0 | 1 | 0 | 0 | **0** |
| 核心技巧 | 8种 | 5种 | 4种 | 10种 | 5种 | **二分+回溯** |
| 重点 | 哈希/窗口 | 链表 | 单调栈 | 二叉树 | 图 | **核心算法** |

---

## 💡 学习心得

1. **二分查找是"条件判断式搜索"**：二分不仅能在有序数组里找数，还能猜答案、找极值、旋转数组——核心都是"根据条件缩小范围"
2. **回溯 = DFS + 状态重置**：和图的 DFS 唯一区别就是回退时要撤销选择。46/78/39/79/22/17 全部共享同一个框架
3. **回溯三要素**：防重复方式（used/start）、终止条件、剪枝条件——每道题就是这三个参数的组合变化
4. **模板化学习效率高**：704→35→34 是"标准二分→插入点→边界"的递进，46→78→39 是"排列→子集→组合"的递进，每道题只变一个条件

---

## 📚 下周计划

| 主题 | 重点题目 | 核心技能 |
|:----|:---------|:---------|
| 动态规划入门 | 基础 DP 题 | 状态定义、转移方程 |
| 链表复习 | 206/234/19 再练 | 巩固基础 |

---

**第六周圆满完成！二分查找 + 回溯模板已掌握！** 🎉

**总进度：78 道题，覆盖 6 大专题！**
