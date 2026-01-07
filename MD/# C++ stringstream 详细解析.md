# C++ stringstream 详细解析

## 1. 基本概念

`stringstream` 是 C++ 标准库中提供的一个**字符串流处理类**，用于在字符串和其他数据类型之间进行转换，以及对字符串进行分割、拼接等操作。

它属于 `<sstream>` 头文件中的类模板，主要有三种类型：
- `istringstream`：用于从字符串读取数据（输入流）
- `ostringstream`：用于向字符串写入数据（输出流）
- `stringstream`：同时支持输入和输出操作（双向流）

## 2. 头文件与命名空间

```cpp
#include <sstream>  // 必须包含此头文件
using namespace std;  // 或者使用 std::stringstream
```

## 3. 主要成员函数

### 3.1 构造函数
```cpp
// 默认构造
stringstream ss;

// 使用字符串初始化
stringstream ss("Hello World");
```

### 3.2 输入操作
```cpp
string s;
int num;
ss >> s;      // 从流中读取字符串（以空白符分隔）
ss >> num;    // 从流中读取整数
```

### 3.3 输出操作
```cpp
ss << "Hello" << " " << "World";
ss << 123;
```

### 3.4 字符串操作
```cpp
string str = ss.str();  // 获取流中的字符串内容
ss.str("New string");  // 设置流中的字符串内容
ss.clear();            // 清空流的状态标志（但不清除内容）
ss.str("");            // 清除流中的内容
```

### 3.5 其他常用操作
```cpp
bool eof() const;      // 检查是否到达流末尾
void seekg(pos_type pos);  // 设置输入流位置
void seekp(pos_type pos);  // 设置输出流位置
```

## 4. stringstream 在路径简化中的应用

### 4.1 问题分析
在 LeetCode 71. 简化路径问题中，需要将 Unix 风格的路径字符串按 `/` 分割成多个目录名，以便进行后续处理。

### 4.2 关键代码
```cpp
stringstream ss(path); // 用路径字符串初始化stringstream
string dir;
while (getline(ss, dir, '/'))  // 按 '/' 分割字符串
{
    // 处理每个目录名
    if (dir.empty() || dir == ".") continue;
    // ...
}
```

### 4.3 详细解析

#### 4.3.1 `getline` 函数
`getline(ss, dir, '/')` 是 stringstream 最常用的分割字符串方法之一，其参数含义：
- `ss`：输入流对象
- `dir`：用于存储读取到的字符串的变量
- `'/'`：分隔符（默认是换行符 `'\n'`）

#### 4.3.2 分割过程示例
以路径 `/home//user/Documents/../Pictures` 为例：

| 迭代 | `getline` 读取内容 | 存储到 `dir` 的值 | 后续处理 |
|------|-------------------|-------------------|----------|
| 1    | 空（`/`前无内容） | `""`              | `continue` |
| 2    | `home`（第一个 `/` 后） | `"home"`          | 加入目录列表 |
| 3    | 空（`//`之间无内容） | `""`              | `continue` |
| 4    | `user`（第二个 `/` 后） | `"user"`          | 加入目录列表 |
| 5    | `Documents`（第三个 `/` 后） | `"Documents"`     | 加入目录列表 |
| 6    | `..`（第四个 `/` 后） | `".."`            | 弹出最后一个目录 |
| 7    | `Pictures`（第五个 `/` 后） | `"Pictures"`      | 加入目录列表 |

#### 4.3.3 处理连续分隔符的优势
`getline` 配合 stringstream 的一个显著优势是**自动处理连续的分隔符**。在上面的例子中，`//` 会被正确处理为两个连续的分隔符，中间的空字符串会被 `if (dir.empty()) continue;` 语句跳过。

## 5. stringstream 的其他常用场景

### 5.1 数据类型转换

#### 字符串转其他类型
```cpp
stringstream ss("123.45");
double num;
ss >> num;  // num = 123.45
```

#### 其他类型转字符串
```cpp
stringstream ss;
ss << 123 << " " << 3.14;
string s = ss.str();  // s = "123 3.14"
```

### 5.2 字符串拼接
```cpp
stringstream ss;
ss << "Hello, " << "World!" << " The answer is " << 42;
string s = ss.str();  // s = "Hello, World! The answer is 42"
```

### 5.3 复杂字符串处理
```cpp
string data = "name:John age:30 city:NewYork";
stringstream ss(data);
string token;

while (getline(ss, token, ':')) {
    // 处理键
    string key = token;
    // 处理值
    if (getline(ss, token, ' ')) {
        string value = token;
        // 使用 key 和 value
    }
}
```

## 6. 优缺点分析

### 优点
1. **类型安全**：自动处理类型转换，避免手动转换的错误
2. **方便灵活**：支持多种数据类型的输入输出操作
3. **内存管理**：自动管理内存，无需手动分配和释放
4. **分隔符处理**：轻松处理各种分隔符，包括连续分隔符

### 缺点
1. **性能开销**：相比直接字符串操作，有一定的性能开销
2. **内存占用**：对于大量数据处理，内存占用较大
3. **状态管理**：需要注意流的状态标志（如 EOF、错误标志）

## 7. 注意事项

1. **清空流内容**：使用 `ss.str("")` 而不是只调用 `ss.clear()`（后者只清空状态标志）
2. **重复使用**：在重复使用同一个 stringstream 对象时，需要同时调用 `clear()` 和 `str("")`
3. **异常处理**：考虑添加异常处理，特别是在处理不可靠的输入时
4. **性能考虑**：对于频繁的字符串处理，考虑使用更高效的方法

## 8. 代码优化建议

在 LeetCode 71 题中，当前的 stringstream 使用方式已经非常高效，但可以考虑以下优化：

```cpp
// 优化前
stringstream ss(path);
string dir;
while (getline(ss, dir, '/')) {
    // 处理逻辑
}

// 优化后（减少对象创建）
stringstream ss;
ss.str(path);  // 先创建对象，再设置内容
string dir;
while (getline(ss, dir, '/')) {
    // 处理逻辑
}
```

## 9. 总结

stringstream 是 C++ 中处理字符串的强大工具，特别适合：
- 字符串与其他数据类型的转换
- 复杂字符串的分割和拼接
- 格式化字符串的构建

在路径简化问题中，stringstream 配合 getline 函数，优雅地解决了按 `/` 分割路径字符串的问题，同时自动处理了连续分隔符的情况，大大简化了代码逻辑。