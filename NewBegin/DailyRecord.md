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