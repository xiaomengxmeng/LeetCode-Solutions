## 2026-04-13 | [Easy] Two Sum (1)

### 🎯 核心思路
使用哈希表存储已遍历元素及其索引，对于每个元素 `nums[i]`，检查 `target - nums[i]` 是否在哈希表中。时间复杂度 O(n)，空间复杂度 O(n)。

### 🔑 关键代码片段
```cpp
unordered_map<int, int> numToIndex;
for (int i = 0; i < nums.size(); i++) {
    int complement = target - nums[i];
    if (numToIndex.count(complement)) {
        return {numToIndex[complement], i};
    }
    numToIndex[nums[i]] = i;
}
return {};
```

### 📚 学到的知识点
- 哈希表的 O(1) 查找特性可以用于"两数之和"类问题
- "以空间换时间"是常用的优化策略
- 遍历时同时构建查找表是一种常见模式
- 先查找后插入的顺序可以避免同一元素被重复使用

### ⚠️ 易错点 & 反思
- ❌ 暴力解法的时间复杂度 O(n²) 在大数据时会超时
- ❌ 索引顺序容易搞反（应该先返回哈希表中的索引）
- 💡 以后看到"查找两个数满足某条件"的问题，优先考虑哈希表
- 💡 对于有序数组，可以考虑双指针法进一步优化空间复杂度

### 🔗 关联题目
- [15] 三数之和 - 扩展到三个数，需要排序 + 双指针
- [18] 四数之和 - 进一步扩展，同样需要排序 + 双指针
- [167] 两数之和 II - 有序数组版本，用双指针更高效

## 2026-04-13 | [Medium] Check if Strings Can Be Made Equal With Operations II (2840)

### 🎯 核心思路
操作的本质是只能在奇偶性相同的位置之间交换字符，因此只需分别比较两个字符串的偶数位置和奇数位置的字符组成是否相同。使用排序后比较的方法，时间复杂度 O(n log n)。

### 🔑 关键代码片段
```cpp
string evenS1, oddS1, evenS2, oddS2;
for (int i = 0; i < s1.size(); i++) {
    if (i % 2 == 0) {
        evenS1 += s1[i];
        evenS2 += s2[i];
    } else {
        oddS1 += s1[i];
        oddS2 += s2[i];
    }
}

sort(evenS1.begin(), evenS1.end());
sort(oddS1.begin(), oddS1.end());
sort(evenS2.begin(), evenS2.end());
sort(oddS2.begin(), oddS2.end());

return evenS1 == evenS2 && oddS1 == oddS2;
```

### 📚 学到的知识点
- 分析操作的本质：j-i是偶数意味着只能在同奇偶性位置交换
- 字符串处理技巧：分离奇偶位置字符
- 字符组成比较方法：排序后比较或统计频率
- 问题分解：将复杂问题分解为两个子问题

### ⚠️ 易错点 & 反思
- ❌ 忘记索引从0开始，导致奇偶位置判断错误
- ❌ 只比较整体字符组成，没有分开奇偶位置
- 💡 对于字符组成比较，排序法和频率统计法各有优劣
- 💡 频率统计法在n较大时更高效（O(n) vs O(n log n)）

### 🔗 关联题目
- [242] Valid Anagram - 字符频率统计
- [387] First Unique Character in a String - 字符频率统计
- [1278] Palindrome Partitioning III - 字符串分割问题

## 2026-04-13 | [Medium] Group Anagrams (49)

### 🎯 核心思路
使用哈希表进行分组，键为排序后的字符串（字母异位词排序后相同），值为字母异位词列表。遍历字符串数组，将每个字符串排序后作为键，将原字符串添加到对应的列表中。时间复杂度 O(n * k log k)，其中k为字符串平均长度。

### 🔑 关键代码片段
```cpp
unordered_map<string, vector<string>> map;
for (const string& str : strs) {
    string key = str;
    sort(key.begin(), key.end());
    map[key].push_back(str);
}
vector<vector<string>> res;
for (const auto& pair : map) {
    res.push_back(pair.second);
}
return res;
```

### 📚 学到的知识点
- 哈希表的高级应用：用于分组和归类
- 键设计的艺术：如何选择合适的键来表示一组具有相同特征的元素
- 字母异位词判断方法：排序后相同或字符频率相同
- 问题分解能力：将复杂问题分解为特征提取和分组两个步骤

### ⚠️ 易错点 & 反思
- ❌ 键设计不当可能导致不同的字符串被视为相同
- ❌ 忘记处理空字符串的情况
- 💡 排序方法简单直观，频率统计方法更高效（O(n*k) vs O(n*k log k)）
- 💡 "分组"模式：将具有相同特征的元素分组，哈希表键为特征，值为元素列表

### 🔗 关联题目
- [242] Valid Anagram - 基础的字母异位词判断
- [438] Find All Anagrams in a String - 滑动窗口 + 字符频率
- [567] Permutation in String - 滑动窗口 + 字符频率

## 2026-04-14 | [Easy] Valid Parentheses (20)

### 🎯 核心思路
使用栈数据结构进行括号匹配。左括号入栈保存，遇到右括号时检查栈顶是否匹配，匹配则出栈。最后判断栈是否为空来确定所有括号是否正确配对。时间复杂度 O(n)，空间复杂度 O(n)。

### 🔑 关键代码片段
```cpp
bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) return false;      // 栈空说明没有匹配的左括号
            if ((c == ')' && st.top() != '(') ||
                (c == ']' && st.top() != '[') ||
                (c == '}' && st.top() != '{'))
                return false;                  // 不匹配
            st.pop();
        }
    }
    return st.empty();                         // 最后栈必须为空
}
```

### 📚 学到的知识点
- **栈的特性**：LIFO（后进先出），完美匹配嵌套结构
- **括号匹配本质**：左括号期待被匹配（入栈），右括号寻找对应左括号（出栈）
- **栈操作原则**：访问 `top()` 前必须确保栈不为空
- **边界情况处理**：只有右括号、不匹配、未完全匹配等场景

### ⚠️ 易错点 & 反思
- ❌ 栈为空时调用 `stack.top()` 会导致未定义行为
- ❌ 空检查位置错误：应该在处理右括号时检查，而非每次循环都检查
- ❌ 忽略了输入只有右括号的特殊情况
- 💡 **关键教训**：必须先检查容器状态，再执行操作
- 💡 **优化思路**：从能运行 → 逻辑正确 → 结构清晰 → 代码优雅

### 🔗 关联题目
- [32] Longest Valid Parentheses - 最长有效括号（Hard，进阶挑战）
- [22] Generate Parentheses - 生成括号组合（回溯法）
- [739] Daily Temperatures - 单调栈应用
- [84] Largest Rectangle in Histogram - 栈的经典应用

## 2026-04-14 | [Easy] Min Stack (155)

### 🎯 核心思路
使用辅助栈来跟踪最小值。主栈存储所有元素正常操作，辅助栈存储当前的最小值历史。当新元素小于等于辅助栈顶时同时入辅助栈，弹出时如果主栈弹出的值等于辅助栈顶则也弹出。所有操作的时间复杂度都是 O(1)，空间复杂度 O(n)。

### 🔑 关键代码片段
```cpp
class MinStack {
private:
    stack<int> main_stack;
    stack<int> min_stack;

public:
    void push(int val) {
        main_stack.push(val);
        if (min_stack.empty() || min_stack.top() >= val) {
            min_stack.push(val);      // 新的最小值或相等值入辅助栈
        }
    }

    void pop() {
        int top_val = main_stack.top();
        main_stack.pop();
        if (top_val == min_stack.top()) {
            min_stack.pop();
        }
    }

    int top() { return main_stack.top(); }

    int getMin() { return min_stack.top(); }  // O(1) 获取最小值
};
```

### 📚 学到的知识点
- **辅助数据结构技术**：用额外空间换取查询效率的提升
- **C++ 类的设计**：成员变量的作用域和生命周期管理
- **边界情况处理**：重复最小值的处理（使用 >= 而不是 >）
- **"空间换时间"思想**：O(n) 空间换取 O(1) 的 getMin() 操作

### ⚠️ 易错点 & 反思
- ❌ 成员变量定义在构造函数内部会导致作用域错误（应该是局部变量）
- ❌ `stack.pop()` 不接受参数，且无返回值
- ❌ pop() 时必须先保存 top 值再弹出，否则无法正确比较
- 💡 **关键教训**：理解 C++ 类的成员变量与局部变量的区别
- 💡 **为什么用 >=**：处理重复最小值的情况，确保每次 pop 后辅助栈顶仍是当前最小值

### 🔗 关联题目
- [232] Implement Queue using Stacks - 用栈实现队列
- [225] Implement Stack using Queues - 用队列实现栈
- [716] Max Stack - 类似设计但获取最大值（进阶）
- [155] Min Stack 变体 - 使用单栈+差值法优化空间

## 2026-04-14 | [Easy] Valid Anagram (242) 【复习题】

### 🎯 核心思路
使用字符频率统计法判断两个字符串是否为字母异位词。创建大小为26的计数数组（对应26个小写字母），遍历第一个字符串增加计数，遍历第二个字符串减少计数，最后检查所有计数器是否归零。时间复杂度 O(n)，空间复杂度 O(1)。

### 🔑 关键代码片段
```cpp
bool isAnagram(string s, string t) {
    vector<int> count(26);              // 字符计数数组（自动初始化为0）
    for (char c : s)
        count[c - 'a']++;             // s 中字符出现次数 +1
    for (char c : t)
        count[c - 'a']--;             // t 中字符出现次数 -1（抵消）
    for (int cnt : count)
        if (cnt != 0) return false;   // 不全为0则不匹配
    return true;
}
```

### 📚 学到的知识点
- **字符频率统计模式**：利用固定大小数组统计字符出现次数
- **"抵消"思想**：一个字符串加，另一个字符串减，最后检查平衡状态
- **空间优化技巧**：利用题目约束（小写字母）使用固定大小的数组实现 O(1) 空间
- **方法选择能力**：能根据具体场景选择最优解法（排序 vs 频率统计）

### ⚠️ 易错点 & 反思
- ❌ vector 初始化语法错误：`vector<int>(26)(0)` 是错误的
- ✅ 正确写法：`vector<int> temp(26)` 或 `vector<int> temp(26, 0)`
- 💡 **复习效果评估**：
  - ✅ 能识别出这是 Group Anagrams 的简化版
  - ✅ 直接选择了更优的频率统计法（昨天用的是排序法）
  - ✅ 代码简洁高效，说明知识已经内化
  - ✅ 复习效果很好！

### 🔗 复习关联
- **基础题**：Valid Anagram (242) ← 当前题目
- **进阶题**：Group Anagrams (49) ← 昨天已完成（排序法）
- **高级题**：Find All Anagrams (438) - 滑动窗口 + 频率统计（待学习）

## 2026-04-14 | [Easy] Plus One (66)

### 🎯 核心思路
模拟加法操作，从数组的最后一位开始加1，处理进位。如果某位加1后变成10，则置0并向前进位；如果所有位都进位，则在数组开头插入1。时间复杂度 O(n)，空间复杂度 O(1)（原地修改，特殊情况除外）。

### 🔑 关键代码片段
```cpp
vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    for (int i = n - 1; i >= 0; i--) {
        digits[i]++;              // 当前位加1
        if (digits[i] < 10) {     // 无进位，直接返回
            return digits;
        }
        digits[i] = 0;            // 有进位，置0继续处理前一位
    }
    digits.insert(digits.begin(), 1);  // 所有位都进位，插入1
    return digits;
}
```

### 📚 学到的知识点
- **进位处理模式**：从低位到高位，遇到10就进位
- **从后往前遍历技巧**：处理进位问题的经典方法
- **提前返回优化**：一旦无进位就返回，减少不必要的遍历
- **数组操作技巧**：`insert()` 在开头插入元素
- **大数运算基础**：数组表示大数，逐位处理（这是大数加法的简化版）

### ⚠️ 易错点 & 反思
- ❌ 进位方向错误：应该从后往前（从低位到高位）处理
- ❌ 忘记处理 [9,9,9] 这种特殊情况：所有位都进位时需要插入新位
- ❌ 没有提前返回优化：导致不必要的遍历
- 💡 **关键技巧**：原地修改 + 提前返回，既节省空间又提高效率
- 💡 **测试用例验证**：
  - [1,2,3] → [1,2,4] ✅ (无进位)
  - [1,2,9] → [1,3,0] ✅ (一位进位)
  - [9,9,9] → [1,0,0,0] ✅ (所有位进位)
  - [0] → [1] ✅ (特殊情况)

### 🔗 关联题目
- [67] Add Binary - 二进制加法，类似的进位处理
- [43] Multiply Strings - 大数乘法，进位处理的进阶
- [415] Add Strings - 大数加法，进位处理的扩展
- [989] Add to Array-Form of Integer - 类似的数组加法问题

## 2026-04-15 | [Medium] Merge Intervals (56)

### 🎯 核心思路
先按区间起点排序，然后遍历合并。维护结果数组，每次将当前区间与结果数组最后一个区间比较：若重叠则合并（更新终点为 max），否则添加新区间。时间复杂度 O(n log n)，空间复杂度 O(n)。

### 🔑 关键代码片段
```cpp
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    if (intervals.empty()) return res;
    
    sort(intervals.begin(), intervals.end());
    res.push_back(intervals[0]);
    
    for (int i = 1; i < intervals.size(); i++) {
        if (res.back()[1] >= intervals[i][0]) {
            res.back()[1] = max(res.back()[1], intervals[i][1]);
        } else {
            res.push_back(intervals[i]);
        }
    }
    return res;
}
```

### 📚 学到的知识点
- **区间问题通用套路**：排序 → 遍历 → 合并/添加
- **二维数组排序**：`sort()` 默认按第一个元素排序
- **res.back() 技巧**：获取最后一个元素，便于比较和修改
- **重叠判断**：`end >= next_start` 表示重叠（端点相连也算重叠）
- **合并公式**：`[start, max(end1, end2)]`

### ⚠️ 易错点 & 反思
- ❌ 忘记排序直接遍历，导致无法正确合并
- ❌ 重叠判断条件写错：应该是 `>=` 而不是 `>`
- 💡 **排序的作用**：让重叠区间相邻，便于顺序处理
- 💡 **端点相连也算重叠**：`[1,4]` 和 `[4,5]` 可合并为 `[1,5]`

### 🔗 关联题目
- [57] Insert Interval - 插入区间（类似思路）
- [252] Meeting Rooms - 判断会议是否冲突
- [253] Meeting Rooms II - 最少会议室数量（进阶）
- [435] Non-overlapping Intervals - 移除最少区间使不重叠

## 2026-04-15 | [Easy] Add Binary (67)

### 🎯 核心思路
[待填写：解题思路]

### 🔑 关键代码片段
```cpp
// 待填写：核心代码
```

### 📚 学到的知识点
- [待填写]

### ⚠️ 易错点 & 反思
- [待填写]

### 🔗 关联题目
- [待填写]