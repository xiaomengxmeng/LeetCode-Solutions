/*
 * @lc app=leetcode.cn id=496 lang=cpp
 * @lcpr version=30204
 *
 * [496] 下一个更大元素 I
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
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> greater_map;
        stack<int> stack;
        for(int x:nums2){
            while (!stack.empty()&&x>stack.top())   
            {
                greater_map[stack.top()] = x;
                stack.pop();
            }
            stack.push(x);
        }
        vector<int> res ;
        for(int x:nums1){
            if(greater_map.count(x)){
                res.push_back(greater_map[x]);
            }else{
                res.push_back(-1);
            }
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,1,2]\n[1,3,4,2].\n
// @lcpr case=end

// @lcpr case=start
// [2,4]\n[1,2,3,4].\n
// @lcpr case=end

 */

