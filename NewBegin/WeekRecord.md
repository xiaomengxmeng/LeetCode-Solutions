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

## 📚 下周计划

根据学习路径，第2周应该学习：

| 主题 | 重点题目 | 核心技能 |
|------|----------|----------|
| 链表进阶 | Swap Nodes in Pairs, Reverse Linked List II | 虚拟头节点、递归 |
| 链表技巧 | Linked List Cycle, Find Middle | 快慢指针检测环 |
| 复习巩固 | 重做本周错题 | 检验知识内化 |

---

## 💡 学习心得

1. **模式识别很重要**：看到"两数之和"→ 哈希表，看到"括号匹配"→ 栈
2. **增量更新是关键**：滑动窗口、频率统计都要避免重复计算
3. **边界条件要仔细**：空数组、空栈、空链表都要处理
4. **代码复用**：很多题目核心逻辑相同，只是细节不同

---

**第一周圆满完成！继续加油！** 🎉
