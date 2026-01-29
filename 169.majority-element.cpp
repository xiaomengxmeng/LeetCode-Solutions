/*
 * @lc app=leetcode.cn id=169 lang=cpp
 * @lcpr version=30204
 *
 * [169] 多数元素
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
        统计数组中出现次数大于n/2的元素
        1. 排序
        2. 统计每个元素出现的次数
        3. 返回出现次数大于n/2的元素
    */
    // int majorityElement(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    //     int n = nums.size();
    //     int res = nums[n / 2];
    //     return res;
    // }
    /*
        Boyer-Moore 投票算法详解
        1. 初始化候选元素 candidate 为 0，出现次数 count 为 0
        2. 遍历数组 nums 中的每个元素 num
        3. 如果 count 为 0，将当前元素 num 设为候选元素 candidate
        4. 如果当前元素 num 与候选元素 candidate 相同，count 加 1；否则，count 减 1
        5. 遍历完成后，candidate 即为多数元素
    */
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }
        return candidate;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,1,1,1,2,2]\n
// @lcpr case=end

 */

