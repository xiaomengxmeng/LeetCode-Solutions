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
- 💡 频率统计法在n较大时更高效（O(n) vs O(n log n))

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