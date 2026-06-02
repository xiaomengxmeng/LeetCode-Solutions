/*
 * @lc app=leetcode.cn id=42 lang=cpp
 * @lcpr version=30204
 *
 * [42] Trapping Rain Water
 *
 * [Review] Original completion: 2026-04-30
 * Key technique: Monotonic stack (row-by-row calculation)
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
    int trap(vector<int>& height) {
        int res = 0, n = height.size();
        stack<int> st;
        for (int i = 0; i < n;i++){
            while (!st.empty()&&height[st.top()]<height[i])
            {
                int top = st.top(); //左边界pop后的st.top()  底部 top 右边界i
                st.pop();
                if(st.empty()) break;
                int sideHeight = min(height[st.top()], height[i]);
                res += (i - st.top() - 1) * (sideHeight - height[top]);
            }
            st.push(i);
        }
        return res;
    }
};
// @lc code=end

/*

// @lcpr case=start
// [0,1,0,2,1,0,1,3,2,1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,2,0,3,2,5]\n
// @lcpr case=end

 */
