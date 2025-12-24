/*
 * @lc app=leetcode.cn id=3074 lang=cpp
 * @lcpr version=30204
 *
 * [3074] 重新分装苹果
 *
 * https://leetcode.cn/problems/apple-redistribution-into-boxes/description/
 *
 * algorithms
 * Easy (72.71%)
 * Likes:    32
 * Dislikes: 0
 * Total Accepted:    25.4K
 * Total Submissions: 33.6K
 * Testcase Example:  '[1,3,2]\n[4,3,1,5,2]'
 *
 * 给你一个长度为 n 的数组 apple 和另一个长度为 m 的数组 capacity 。
 * 
 * 一共有 n 个包裹，其中第 i 个包裹中装着 apple[i] 个苹果。同时，还有 m 个箱子，第 i 个箱子的容量为 capacity[i]
 * 个苹果。
 * 
 * 请你选择一些箱子来将这 n 个包裹中的苹果重新分装到箱子中，返回你需要选择的箱子的 最小 数量。
 * 
 * 注意，同一个包裹中的苹果可以分装到不同的箱子中。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：apple = [1,3,2], capacity = [4,3,1,5,2]
 * 输出：2
 * 解释：使用容量为 4 和 5 的箱子。
 * 总容量大于或等于苹果的总数，所以可以完成重新分装。
 * 
 * 
 * 示例 2：
 * 
 * 输入：apple = [5,5,5], capacity = [2,4,2,7]
 * 输出：4
 * 解释：需要使用所有箱子。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n == apple.length <= 50
 * 1 <= m == capacity.length <= 50
 * 1 <= apple[i], capacity[i] <= 50
 * 输入数据保证可以将包裹中的苹果重新分装到箱子中。
 * 
 * 
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
    //排序+贪心
    //先计算所有苹果的数量，然后将箱子数量从大到小排序
    //每次选择最大的箱子，直到所有苹果都被分装完
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int count =0;
        for(int i=0;i<apple.size();i++){
            count+=apple[i];
        }
        sort(capacity.begin(),capacity.end(),greater<int>());
        int ans=0;
        for(int i=0;i<capacity.size();i++){
            ans++;
            count-=capacity[i];
            if(count<=0) break;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,2]\n[4,3,1,5,2]\n
// @lcpr case=end

// @lcpr case=start
// [5,5,5]\n[2,4,2,7]\n
// @lcpr case=end

 */

