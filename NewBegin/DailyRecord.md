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
模拟二进制加法，从两个字符串末尾开始相加，处理进位。使用 `sum / 2` 计算进位，`sum % 2` 计算当前位。正向拼接结果后反转。时间复杂度 O(max(m,n))，空间复杂度 O(max(m,n))。

### 🔑 关键代码片段
```cpp
string addBinary(string a, string b) {
    string res;
    int i = a.size() - 1, j = b.size() - 1, carry = 0;
    
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        carry = sum / 2;
        res += to_string(sum % 2);
    }
    
    reverse(res.begin(), res.end());
    return res;
}
```

### 📚 学到的知识点
- **通用进位模式**：`carry = sum / base`，`current = sum % base`
- **多操作数相加**：循环条件 `i>=0 || j>=0 || carry` 处理所有情况
- **字符串反转技巧**：正向拼接后反转，比反向插入更高效
- **字符转数字**：`c - '0'` 快速转换

### ⚠️ 易错点 & 反思
- ❌ 忘记循环条件包含 `carry`，导致最后进位丢失
- ❌ 字符串长度不同时没有正确处理边界
- 💡 **与 Plus One 的联系**：都是"从后往前 + 进位处理"模式
- 💡 **通用公式**：任意进制加法都可用 `sum / base` 和 `sum % base`

### 🔗 关联题目
- [66] Plus One - 进位处理基础
- [415] Add Strings - 十进制字符串加法
- [43] Multiply Strings - 大数乘法（进阶）

## 2026-04-15 | [Easy] Add Strings (415)

### 🎯 核心思路
模拟十进制加法，从两个字符串末尾开始相加，处理进位。使用 `sum / 10` 计算进位，`sum % 10` 计算当前位。与 Add Binary 几乎完全相同，只需改进制数。时间复杂度 O(max(m,n))，空间复杂度 O(max(m,n))。

### 🔑 关键代码片段
```cpp
string addStrings(string num1, string num2) {
    int i = num1.size() - 1;  // 注意：必须是 size() - 1
    int j = num2.size() - 1;
    int carry = 0;
    string res = "";
    
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        carry = sum / 10;
        res += to_string(sum % 10);
    }
    
    reverse(res.begin(), res.end());
    return res;
}
```

### 📚 学到的知识点
- **进制通用公式**：`carry = sum / base`，`current = sum % base`
- **代码复用**：不同进制加法只需改一个数字（2 → 10）
- **索引陷阱**：`size()` 返回长度，最后一个索引是 `size() - 1`

### ⚠️ 易错点 & 反思
- ❌ `int i = num1.size()` 导致越界访问，应该是 `size() - 1`
- 💡 **与 Add Binary 的联系**：核心逻辑完全相同，只是进制不同
- 💡 **通用模式**：任意进制加法都可用同一套代码

### 🔗 关联题目
- [67] Add Binary - 二进制加法
- [66] Plus One - 进位处理基础
- [43] Multiply Strings - 大数乘法（进阶）

## 2026-04-15 | [Medium] Find All Anagrams in a String (438)

### 🎯 核心思路
使用滑动窗口 + 频率统计。固定窗口大小为 p.size()，维护 count 数组记录差值，用 matched 变量增量更新匹配状态。每次窗口滑动只需 O(1) 更新。时间复杂度 O(n)，空间复杂度 O(1)。

### 🔑 关键代码片段
```cpp
// 滑动窗口核心逻辑
for (int i = p.size(); i < s.size(); i++) {
    // 进入字符
    count[s[i] - 'a']--;
    if (count[s[i] - 'a'] == 0) matched++;
    else if (count[s[i] - 'a'] == -1) matched--;
    
    // 离开字符
    count[s[i - p.size()] - 'a']++;
    if (count[s[i - p.size()] - 'a'] == 0) matched++;
    else if (count[s[i - p.size()] - 'a'] == 1) matched--;
    
    if (matched == p_count) res.push_back(i - p.size() + 1);
}
```

### 📚 学到的知识点
- **滑动窗口模板**：固定窗口大小 + 增量更新
- **matched 增量更新**：O(1) 判断是否匹配，避免每次遍历
- **count 变化的含义**：0→匹配，±1→不匹配
- **窗口索引**：起始 = `i - window_size + 1`

### ⚠️ 易错点 & 反思
- ❌ 用遍历方式计算 matched，失去滑动窗口 O(1) 优势
- ❌ 进入/离开字符时检查了错误的字符
- ❌ 索引计算错误：起始索引应该是 `i - p.size() + 1`
- 💡 **关键技巧**：增量更新 matched，只关注 count 变化

### 🔗 关联题目
- [242] Valid Anagram - 频率统计基础
- [567] Permutation in String - 类似滑动窗口
- [3] Longest Substring Without Repeating Characters - 滑动窗口经典

## 2026-04-16 | [Medium] Longest Substring Without Repeating Characters (3)

### 🎯 核心思路
使用变长滑动窗口。右边界不断扩展，遇到重复字符时左边界跳跃更新到重复字符之后。用 pos 数组记录每个字符最后出现的位置，O(1) 判断是否在窗口内。时间复杂度 O(n)，空间复杂度 O(1)。

### 🔑 关键代码片段
```cpp
int lengthOfLongestSubstring(string s) {
    vector<int> pos(128, -1);
    int left = 0, maxLen = 0;
    
    for (int i = 0; i < s.size(); i++) {
        if (pos[s[i]] >= left) {
            left = pos[s[i]] + 1;  // 跳到重复字符之后
        }
        pos[s[i]] = i;
        maxLen = max(maxLen, i - left + 1);
    }
    return maxLen;
}
```

### 📚 学到的知识点
- **变长滑动窗口**：左右边界独立移动
- **跳跃更新**：`left = pos[c] + 1`，O(1) 跳过重复字符
- **pos 数组技巧**：记录最后位置，快速判断是否在窗口内
- **窗口大小计算**：`i - left + 1`

### ⚠️ 易错点 & 反思
- ❌ `left = i` 导致窗口变空，应该是 `left = pos[s[i]] + 1`
- 💡 **关键技巧**：`pos[s[i]] >= left` 判断重复字符是否在窗口内
- 💡 **与固定窗口的区别**：左边界可以跳跃，不是每次移动1步

### 🔗 关联题目
- [438] Find All Anagrams - 固定窗口滑动
- [567] Permutation in String - 固定窗口
- [76] Minimum Window Substring - 变长窗口进阶

## 2026-04-16 | [Medium] Permutation in String (567)

### 🎯 核心思路
与 Find Anagrams 几乎完全相同，固定窗口大小滑动，用 matched 变量增量更新匹配状态。区别是只需返回是否存在，找到即返回 true。时间复杂度 O(n)，空间复杂度 O(1)。

### 🔑 关键代码片段
```cpp
bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) return false;
    
    vector<int> count(26);
    for (char c : s1) count[c - 'a']++;
    
    int s1_count = 0, match = 0;
    for (int c : count) if (c != 0) s1_count++;
    
    // 初始化 + 滑动窗口（与 Find Anagrams 相同）
    // 找到匹配立即返回 true
}
```

### 📚 学到的知识点
- **代码复用**：相同滑动窗口模式解决不同问题
- **提前返回优化**：找到答案立即返回
- **离开字符的 match 更新**：`count[c]++` 后检查 `== 1`

### ⚠️ 易错点 & 反思
- ❌ 离开字符时检查 `== -1`，应该是 `== 1`
- 💡 **与 Find Anagrams 的关系**：核心逻辑完全相同，只是返回值不同
- 💡 **模式识别**：看到"排列/异位词"就要想到滑动窗口 + 频率统计

### 🔗 关联题目
- [438] Find All Anagrams - 相同逻辑，返回所有索引
- [242] Valid Anagram - 频率统计基础
- [567] Permutation in String - 本题

## 2026-04-17 | [Easy] Move Zeroes (283)

### 🎯 核心思路
使用快慢指针。快指针遍历数组，慢指针记录下一个非零元素应放置的位置。遇到非零元素放到慢指针位置，最后把慢指针之后的位置填 0。时间复杂度 O(n)，空间复杂度 O(1)。

### 🔑 关键代码片段
```cpp
void moveZeroes(vector<int>& nums) {
    int slow = 0;
    for (int fast = 0; fast < nums.size(); fast++) {
        if (nums[fast] != 0) {
            nums[slow++] = nums[fast];
        }
    }
    while (slow < nums.size()) {
        nums[slow++] = 0;
    }
}
```

### 📚 学到的知识点
- **快慢指针模式**：一个遍历，一个记录位置
- **原地操作技巧**：先覆盖非零元素，后填 0
- **顺序保持原理**：从前往后遍历 = 保持原顺序
- **双指针分类**：快慢指针、左右指针

### ⚠️ 易错点 & 反思
- ❌ 从后往前遍历会反转顺序
- 💡 **关键技巧**：慢指针记录"下一个放置位置"
- 💡 **模式识别**：原地移动/删除元素 → 快慢指针

### 🔗 关联题目
- [27] Remove Element - 类似的快慢指针
- [26] Remove Duplicates - 快慢指针去重
- [80] Remove Duplicates II - 快慢指针进阶

## 2026-04-17 | [Easy] Remove Element (27)

### 🎯 核心思路
与 Move Zeroes 几乎相同，使用快慢指针原地移除等于 val 的元素。快指针遍历，慢指针记录放置位置。区别是不需要最后填 0，直接返回 slow 作为新长度。时间复杂度 O(n)，空间复杂度 O(1)。

### 🔑 关键代码片段
```cpp
int removeElement(vector<int>& nums, int val) {
    int slow = 0;
    for (int fast = 0; fast < nums.size(); fast++) {
        if (nums[fast] != val) {
            nums[slow++] = nums[fast];
        }
    }
    return slow;
}
```

### 📚 学到的知识点
- **快慢指针通用模式**：原地移除/过滤元素
- **代码简化**：不需要填 0 时更简洁
- **模式识别**：原地操作 + 保持顺序 → 快慢指针

### ⚠️ 易错点 & 反思
- 💡 **与 Move Zeroes 的关系**：核心逻辑完全相同，只是目标不同
- 💡 **返回值**：slow 就是新长度

### 🔗 关联题目
- [283] Move Zeroes - 快慢指针基础
- [26] Remove Duplicates - 快慢指针去重
- [80] Remove Duplicates II - 快慢指针进阶

## 2026-04-17 | [Easy] Reverse Linked List (206)

### 🎯 核心思路
使用三指针法反转链表。prev 指向前一个节点，cur 指向当前节点，next 临时保存下一个节点。每次循环：保存 next → 反转指针 → 移动 prev 和 cur。时间复杂度 O(n)，空间复杂度 O(1)。

### 🔑 关键代码片段
```cpp
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* cur = head;
    
    while (cur != nullptr) {
        ListNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
```

### 📚 学到的知识点
- **链表操作核心**：改变指针方向
- **三指针法**：prev、cur、next 配合
- **临时保存**：改变指针前先保存 next，防止丢失
- **返回值**：prev 是新的头节点

### ⚠️ 易错点 & 反思
- ❌ prev 初始指向头节点会造成循环引用
- ❌ 循环条件 `cur->next == nullptr` 会漏掉最后一个节点
- 💡 **关键技巧**：先保存 next，再改变指针
- 💡 **链表 vs 数组**：链表只能顺序访问，操作时注意保存指针

### 🔗 关联题目
- [92] Reverse Linked List II - 反转部分链表
- [25] Reverse Nodes in k-Group - K个一组反转
- [24] Swap Nodes in Pairs - 两两交换节点

## 2026-04-21 | [Medium] Swap Nodes in Pairs (24)

### 🎯 核心思路
使用虚拟头节点统一处理边界情况，两两交换相邻节点。关键原则：先连后断，先存后改。迭代版 O(1) 空间，递归版更简洁但 O(n) 空间。

### 🔑 关键代码片段
```cpp
// 迭代版
ListNode* swapPairs(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    
    while (prev->next && prev->next->next) {
        ListNode* cur = prev->next;
        ListNode* n1 = cur->next;
        ListNode* n2 = n1->next;
        
        prev->next = n1;
        n1->next = cur;
        cur->next = n2;
        prev = cur;
    }
    return dummy->next;
}

// 递归版
ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* n1 = head->next;
    head->next = swapPairs(n1->next);
    n1->next = head;
    return n1;
}
```

### 📚 学到的知识点
- **虚拟头节点**：统一处理头节点边界情况
- **交换顺序原则**：先连后断，先存后改
- **循环转递归模板**：终止条件 → 处理当前 → 递归调用
- **递归 vs 迭代**：递归简洁但空间高，迭代高效但代码长

### ⚠️ 易错点 & 反思
- ❌ 循环条件用 `||` 导致空指针崩溃，应该用 `&&`
- ❌ 循环条件用 `head` 而不是 `prev->next`，head 不会更新
- 💡 **交换顺序**：必须先保存 n2，再改变指针
- 💡 **循环→递归**：while 条件 → if 终止，变量更新 → 递归调用

### 🔗 关联题目
- [206] Reverse Linked List - 链表反转基础
- [25] Reverse Nodes in k-Group - K个一组反转（进阶）
- [92] Reverse Linked List II - 反转部分链表

## 2026-04-21 | [Easy] Linked List Cycle (141)

### 🎯 核心思路
使用快慢指针检测环。快指针每次走2步，慢指针每次走1步。如果链表有环，快指针最终会追上慢指针；如果无环，快指针会到达 nullptr。时间复杂度 O(n)，空间复杂度 O(1)。

### 🔑 关键代码片段
```cpp
// 快慢指针法（O(1) 空间）
bool hasCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

// 哈希表法（O(n) 空间）
bool hasCycle(ListNode *head) {
    unordered_set<ListNode*> visited;
    while (head) {
        if (visited.count(head)) return true;
        visited.insert(head);
        head = head->next;
    }
    return false;
}
```

### 📚 学到的知识点
- **快慢指针原理**：快指针比慢指针每轮多走1步，环内距离逐渐缩短直到相遇
- **循环条件**：`fast && fast->next`，确保快指针可以安全走两步
- **两种方法对比**：快慢指针 O(1) 空间更优，哈希表更直观

### ⚠️ 易错点 & 反思
- ❌ 循环条件写 `fast->next` 而不是 `fast`，当 head 为空时崩溃
- ❌ 检查 `slow->next` 没有意义，慢指针不需要提前判断
- ❌ 快指针移动方式不标准，应该 `fast->next->next` 一次走两步
- 💡 **关键技巧**：先检查指针非空，再访问其 next

### 🔗 关联题目
- [142] Linked List Cycle II - 找到环的入口节点
- [876] Middle of the Linked List - 快慢指针找中点
- [202] Happy Number - 快慢指针检测循环

## 2026-04-21 | [Medium] Linked List Cycle II (142)

### 🎯 核心思路
分两步：① 快慢指针找到相遇点 ② 从相遇点和头节点同时出发，速度相同，相遇点即为入口。数学推导：a = c（头到入口距离 = 相遇点到入口距离）。

### 🔑 关键代码片段
```cpp
ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    
    // Step 1: 找相遇点
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    
    // 无环
    if (!fast || !fast->next) return nullptr;
    
    // Step 2: 找入口（a = c）
    ListNode *p1 = head, *p2 = slow;
    while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}
```

### 📚 学到的知识点
- **数学推导**：`a = nr - b = c`，头到入口 = 相遇点到入口
- **两阶段法**：先找相遇点，再找入口
- **与 [141] 的关系**：[141] 是判断，[142] 是定位

### ⚠️ 易错点 & 反思
- ❌ 忘记检查无环情况：`!fast || !fast->next`
- ❌ 第二步两个指针速度不同，应该都是 1 步
- 💡 **关键理解**：相遇点不是入口，但可以用来找入口

### 🔗 关联题目
- [141] Linked List Cycle - 判断是否有环
- [876] Middle of the Linked List - 快慢指针找中点
- [287] Find the Duplicate Number - 类似环检测思想

## 2026-04-21 | [Easy] Middle of the Linked List (876)

### 🎯 核心思路
快指针走2步，慢指针走1步。当快指针到达末尾时，慢指针正好在中点。循环条件 `fast && fast->next` 自动处理奇偶情况，偶数时返回第二个中间节点。

### 🔑 关键代码片段
```cpp
ListNode* middleNode(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
```

### 📚 学到的知识点
- **快慢指针找中点**：快指针到末尾，慢指针在中点
- **循环条件**：`fast && fast->next` 自动处理奇偶
- **三种应用统一**：[141][142][876] 都用相同条件

### ⚠️ 易错点 & 反思
- ❌ 循环条件用 `||` 而不是 `&&`
- ❌ 手动处理奇偶情况，其实循环条件自动处理
- 💡 **扩展思考**：返回第一个中间节点可用 prev 指针记录

### 🔗 关联题目
- [141] Linked List Cycle - 快慢指针检测环
- [142] Linked List Cycle II - 快慢指针找入口
- [234] Palindrome Linked List - 找中点 + 反转

## 2026-04-22 | [Easy] Merge Two Sorted Lists (21)

### 🎯 核心思路
使用虚拟头节点 + tail 指针，逐个比较两个有序链表的节点值，将较小的节点连接到新链表末尾。循环结束后连接剩余节点。时间复杂度 O(n+m)，空间复杂度 O(1)。

### 🔑 关键代码片段
```cpp
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode *dummy = new ListNode();
    ListNode *tail = dummy;
    
    while (list1 && list2) {
        if (list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    
    tail->next = list1 ? list1 : list2;
    return dummy->next;
}
```

### 📚 学到的知识点
- **虚拟头节点**：统一处理第一个节点的连接
- **稳定性**：`<=` 保证相等元素的相对顺序不变
- **迭代 vs 递归**：迭代 O(1) 空间，递归 O(n) 栈空间

### ⚠️ 易错点 & 反思
- ❌ 连接剩余节点时写反了：`if (list1) tail->next = list2`
- ✅ 正确：`if (list1) tail->next = list1`
- 💡 **记忆方法**：谁不为空就连谁

### 🔗 关联题目
- [23] Merge k Sorted Lists - 合并K个有序链表
- [148] Sort List - 归并排序链表
- [88] Merge Sorted Array - 数组版本

## 2026-04-22 | [Easy] Remove Duplicates from Sorted List (83)

### 🎯 核心思路
利用有序链表的特点，重复元素相邻。用单指针遍历，当 `cur->val == cur->next->val` 时跳过下一个节点（cur 不移动），否则移动 cur。时间复杂度 O(n)，空间复杂度 O(1)。

### 🔑 关键代码片段
```cpp
ListNode* deleteDuplicates(ListNode* head) {
    ListNode *cur = head;
    while (cur && cur->next) {
        if (cur->val == cur->next->val) {
            cur->next = cur->next->next;  // 跳过，cur不移动
        } else {
            cur = cur->next;  // 不相等，移动cur
        }
    }
    return head;
}
```

### 📚 学到的知识点
- **有序链表去重**：重复元素相邻，单指针即可
- **cur 移动时机**：相等时不移动，不相等时移动
- **虚拟头节点判断**：头节点不删除则不需要

### ⚠️ 易错点 & 反思
- ❌ 相等时移动 cur，导致连续重复处理不完整
- ✅ 相等时 cur 不移动，继续检查下一个
- 💡 **与数组去重 [26] 联系**：核心思想相同，都是利用有序性

### 🔗 关联题目
- [82] Remove Duplicates from Sorted List II - 删除所有重复
- [26] Remove Duplicates from Sorted Array - 数组版本
- [27] Remove Element - 数组删除元素

## 2026-04-22 | [Easy] Remove Linked List Elements (203)

### 🎯 核心思路
使用虚拟头节点 + cur 指针遍历。检查 `cur->next->val == val`，相等则跳过（删除），不等则移动 cur。时间复杂度 O(n)，空间复杂度 O(1)。

### 🔑 关键代码片段
```cpp
ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* cur = dummy;
    
    while (cur->next) {
        if (cur->next->val == val) {
            cur->next = cur->next->next;  // 删除，cur不移动
        } else {
            cur = cur->next;  // 不相等，移动cur
        }
    }
    return dummy->next;
}
```

### 📚 学到的知识点
- **虚拟头节点**：头节点可能被删除时必须使用
- **cur 位置**：指向待检查节点的前一个
- **遍历对象**：检查 cur->next 而非 cur

### ⚠️ 易错点 & 反思
- ❌ cur 指向 head，无法检查头节点
- ✅ cur 指向 dummy，检查头节点时就是 dummy->next
- 💡 **与 [27] 联系**：都是删除特定值，核心思想相同

### 🔗 关联题目
- [27] Remove Element - 数组删除特定值
- [83] Remove Duplicates - 有序链表去重
- [82] Remove Duplicates II - 删除所有重复

## 2026-04-22 | [Easy] Palindrome Linked List (234)

### 🎯 核心思路
三步法：① 快慢指针找中点 ② 反转后半部分 ③ 双指针比较。时间复杂度 O(n)，空间复杂度 O(1)。综合了 [876] 找中点和 [206] 反转链表。

### 🔑 关键代码片段
```cpp
bool isPalindrome(ListNode* head) {
    // Step 1: 找中点
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Step 2: 反转后半部分
    ListNode *prev = nullptr, *cur = slow;
    while (cur) {
        ListNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    
    // Step 3: 比较
    ListNode *left = head, *right = prev;
    while (right) {
        if (left->val != right->val) return false;
        left = left->next;
        right = right->next;
    }
    return true;
}
```

### 📚 学到的知识点
- **技巧综合**：找中点 + 反转 + 比较
- **奇偶自动处理**：用 `while(right)` 作为条件
- **恢复链表**：面试可能要求恢复原链表

### ⚠️ 易错点 & 反思
- ❌ 用 `while(left)` 作为条件，奇数时会多比较一次
- ✅ 用 `while(right)` 自动处理奇数情况
- 💡 **综合题价值**：检验多个技巧的掌握程度

### 🔗 关联题目
- [876] Middle of the Linked List - 找中点
- [206] Reverse Linked List - 反转链表
- [143] Reorder List - 重排链表

## 2026-04-23 | [Easy] Intersection of Two Linked Lists (160)

### 🎯 核心思路
双指针走两遍法。pa 走完链表A后跳到链表B，pb 走完链表B后跳到链表A。两个指针走的步数相同（a+b+c），会在相交点相遇。如果不相交，都会走到 nullptr。时间复杂度 O(m+n)，空间复杂度 O(1)。

### 🔑 关键代码片段
```cpp
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *pa = headA, *pb = headB;
    while (pa != pb) {
        pa = pa ? pa->next : headB;
        pb = pb ? pb->next : headA;
    }
    return pa;
}
```

### 📚 学到的知识点
- **双指针走两遍**：消除长度差异
- **简洁写法**：三元运算符处理指针切换
- **数学原理**：a + b + c = a + c + b

### ⚠️ 易错点 & 反思
- ❌ 只走一遍，无法同步到达相交点
- ✅ 走两遍，消除长度差异
- 💡 **技巧**：指针走到末尾后跳到另一个链表头

### 🔗 关联题目
- [141] Linked List Cycle - 快慢指针相遇
- [142] Linked List Cycle II - 找相遇点

## 2026-04-24 | [Medium] Remove Nth Node From End of List (19)

### 🎯 核心思路
快慢指针 + 虚拟头节点。快指针先走 n 步建立间隔，然后快慢指针同时移动。当快指针到达末尾时，慢指针正好在倒数第 n 个节点的前一个位置。时间复杂度 O(n)，空间复杂度 O(1)。

### 🔑 关键代码片段
```cpp
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *dummy = new ListNode(0, head);
    ListNode *fast = dummy, *slow = dummy;
    
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }
    
    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    
    slow->next = slow->next->next;
    return dummy->next;
}
```

### 📚 学到的知识点
- **快慢指针间隔**：快指针先走 n 步建立间隔
- **虚拟头节点**：处理删除头节点情况
- **一次遍历**：满足进阶要求

### ⚠️ 易错点 & 反思
- ❌ 快指针走 n+1 步，导致 slow 指向要删除的节点而非前一个
- ✅ 快指针走 n 步，slow 正好指向删除节点的前一个
- 💡 **关键**：slow 要停在删除节点的前一个位置

### 🔗 关联题目
- [876] Middle of the Linked List - 快慢指针找中点
- [203] Remove Linked List Elements - 删除节点

## 2026-04-24 | [Medium] Add Two Numbers (2)

### 🎯 核心思路
模拟手动加法，逐位相加并处理进位。用虚拟头节点 + tail 指针构建新链表。循环条件 `l1 || l2 || carry` 确保处理最后还有进位的情况。时间复杂度 O(max(m,n))，空间复杂度 O(max(m,n))。

### 🔑 关键代码片段
```cpp
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
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
}
```

### 📚 学到的知识点
- **模拟手动加法**：逐位相加，处理进位
- **虚拟头节点 + tail**：构建新链表的标准模式
- **循环条件**：`l1 || l2 || carry` 处理最后进位

### ⚠️ 易错点 & 反思
- ❌ 直接访问 `l1->val`，空指针崩溃
- ❌ 用 `dummy->next = node` 覆盖，只保留最后一个节点
- ✅ 用 `tail` 指针跟踪末尾，正确连接
- 💡 **关键**：三元运算符处理空指针

### 🔗 关联题目
- [67] Add Binary - 二进制加法
- [415] Add Strings - 字符串加法
- [445] Add Two Numbers II - 正序存储版本

## 2026-04-27 | [Easy] Implement Queue using Stacks (232)

### 🎯 核心思路
用两个栈实现队列：栈1负责入队，栈2负责出队。关键优化：只有当栈2为空时，才将栈1的元素全部倒入栈2。每个元素最多移动2次，均摊时间复杂度 O(1)。

### 🔑 关键代码片段
```cpp
class MyQueue {
    stack<int> s1, s2;  // s1入队，s2出队
public:
    void push(int x) { s1.push(x); }
    
    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int res = s2.top();
        s2.pop();
        return res;
    }
    
    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() { return s1.empty() && s2.empty(); }
};
```

### 📚 学到的知识点
- **栈实现队列**：两个栈配合，一个入一个出
- **均摊复杂度**：每个元素最多移动2次，均摊O(1)
- **延迟倒栈**：只有栈2空时才倒栈，避免重复操作

### ⚠️ 易错点 & 反思
- ❌ 每次 pop 都倒栈，O(n) 复杂度
- ✅ 栈2空时才倒栈，均摊 O(1)
- 💡 **关键优化**：栈2的元素顺序已经是队列顺序

### 🔗 关联题目
- [225] Implement Stack using Queues - 用队列实现栈
- [155] Min Stack - 栈的变体

## 2026-04-27 | [Easy] Implement Stack using Queues (225)

### 🎯 核心思路
用一个队列实现栈。每次 push 时，先入队，再把前面 size-1 个元素移到队尾，让新元素在队头。push O(n)，pop/top O(1)。

### 🔑 关键代码片段
```cpp
class MyStack {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int res = q.front();
        q.pop();
        return res;
    }
    
    int top() { return q.front(); }
    bool empty() { return q.empty(); }
};
```

### 📚 学到的知识点
- **队列实现栈**：push时重排，让新元素在队头
- **单队列足够**：不需要两个队列
- **复杂度权衡**：push O(n) vs pop O(1)

### ⚠️ 易错点 & 反思
- ❌ 队列倒来倒去顺序不变（与栈不同！）
- ✅ push时重排，让最后入队的在队头
- 💡 **对比 [232]**：栈倒栈顺序反，队列倒队列顺序不变

### 🔗 关联题目
- [232] Implement Queue using Stacks - 栈实现队列
- [155] Min Stack - 栈的变体
