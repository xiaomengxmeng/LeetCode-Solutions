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
