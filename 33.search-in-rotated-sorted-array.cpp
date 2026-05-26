/*
 * @lc app=leetcode.cn id=33 lang=cpp
 * @lcpr version=30204
 *
 * [33] 搜索旋转排序数组
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
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            // 判断 mid 在左段还是右段
            if (nums[0] <= nums[mid]) {
                // mid 在左段（大段）
                // target 在左段 且 在 mid 左边 → 往左搜
                if (nums[0] <= target && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;  // 否则往右搜
            } else {
                // mid 在右段（小段）
                // target 在右段 且 在 mid 右边 → 往右搜
                if (nums[0] > target && nums[mid] < target)
                    left = mid + 1;
                else
                    right = mid - 1;  // 否则往左搜
            }
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,5,6,7,0,1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [4,5,6,7,0,1,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */

