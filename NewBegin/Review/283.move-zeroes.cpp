/*
 * @lc app=leetcode.cn id=283 lang=cpp
 * @lcpr version=30204
 *
 * [283] Move Zeroes
 * 
 * [Review] Original completion: 2026-04-17
 * Key technique: Two pointers
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
    void moveZeroes(vector<int>& nums) {

        int fast, slow = 0;
        for (fast = 0; fast < nums.size();fast++){
            if(nums[fast]!=0){
                nums[slow++] = nums[fast];
            }
        }
        while (slow< nums.size())
        {
            nums[slow++] = 0;
        }
    }
};
// @lc code=end

/*

// @lcpr case=start
// [0,1,0,3,12]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */
