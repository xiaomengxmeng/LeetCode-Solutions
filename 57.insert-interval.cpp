/*
 * @lc app=leetcode.cn id=57 lang=cpp
 * @lcpr version=30204
 *
 * [57] 插入区间
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
        给你一个 无重叠的 ，按照区间起始端点排序的区间列表 intervals，
        其中 intervals[i] = [starti, endi] 表示第 i 个区间的开始和结束，
        并且 intervals 按照 starti 升序排列。同样给定一个区间
        newInterval = [start, end] 表示另一个区间的开始和结束。
        在 intervals 中插入区间 newInterval，使得 intervals 依然按照 starti 升序排列，
        且区间之间不重叠（如果有必要的话，可以合并区间）。
        返回插入之后的 intervals。
        注意 你不需要原地修改 intervals。你可以创建一个新数组然后返回它。
        先看newInterval的开始位置，如果newInterval的结束位置小于intervals[i]的开始位置，
        说明newInterval在intervals[i]的左边，直接将newInterval插入到intervals[i]的左边即可。
        如果newInterval的开始位置大于intervals[i]的结束位置，
        说明newInterval在intervals[i]的右边，直接将newInterval插入到intervals[i]的右边即可。
        如果newInterval的开始位置小于等于intervals[i]的结束位置，
        说明newInterval和intervals[i]有重叠，
        我们需要合并这两个区间，
        合并后的区间的开始位置为min(newInterval[0], intervals[i][0])，
        合并后的区间的结束位置为max(newInterval[1], intervals[i][1])。
    */
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0;
        while(i<intervals.size()&&intervals[i][1]<newInterval[0])
            res.push_back(intervals[i++]);
        while(i<intervals.size()&&intervals[i][0]<=newInterval[1]){
            // 新的区间 范围
            newInterval[0] = min(newInterval[0], intervals[i][0]); // 更新合并后的区间的开始位置
            newInterval[1] = max(newInterval[1], intervals[i][1]); // 更新合并后的区间的结束位置
            i++;
        }
        res.push_back(newInterval);
        while(i<intervals.size())
            res.push_back(intervals[i++]);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,3],[6,9]]\n[2,5]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[3,5],[6,7],[8,10],[12,16]]\n[4,8]\n
// @lcpr case=end

 */

