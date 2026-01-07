/*
 * @lc app=leetcode.cn id=71 lang=cpp
 * @lcpr version=30204
 *
 * [71] 简化路径
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    /*
        在 Unix 风格的文件系统中规则如下：
        一个点 '.' 表示当前目录本身。
        此外，两个点 '..' 表示将目录切换到上一级（指向父目录）。
        任意多个连续的斜杠（即，'//' 或 '///'）都被视为单个斜杠 '/'。
        任何其他格式的点（例如，'...' 或 '....'）均被视为有效的文件/目录名称。
        返回的 简化路径 必须遵循下述格式：

        始终以斜杠 '/' 开头。
        两个目录名之间必须只有一个斜杠 '/' 。
        最后一个目录名（如果存在）不能 以 '/' 结尾。
        此外，路径仅包含从根目录到目标文件或目录的路径上的目录（即，不含 '.' 或 '..'）。
        思路 先找到所有的目录名，然后根据规则简化路径。
        具体实现：
        1. 使用字符串流将路径按 '/' 分割成多个目录名。
        2. 遍历目录名，根据规则进行简化。
        3. 最后根据简化后的目录名，重新构建路径。

    */
    string simplifyPath(string path) {
        vector<string> dirs;
        stringstream ss(path); // 按 '/' 分割路径
        string dir;
        while (getline(ss,dir,'/'))     
        {       
            if(dir.empty()||dir ==".") continue;
            if(dir==".."){
                if(!dirs.empty())
                    dirs.pop_back();
            }
            else
                dirs.push_back(dir);
        }
        string res = "/";
        for(const string &d:dirs){
            res += d + "/";
        }
        if(res.length()>1) // 去掉最后一个 '/'
            res.pop_back();
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "/home/"\n
// @lcpr case=end

// @lcpr case=start
// "/home//foo/"\n
// @lcpr case=end

// @lcpr case=start
// "/home/user/Documents/../Pictures"\n
// @lcpr case=end

// @lcpr case=start
// "/../"\n
// @lcpr case=end

// @lcpr case=start
// "/.../a/../b/c/../d/./"\n
// @lcpr case=end

 */

