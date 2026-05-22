/*
 * @lc app=leetcode.cn id=234 lang=cpp
 * @lcpr version=30204
 *
 * [234] Palindrome Linked List
 * 
 * [Review] Original completion: 2026-04-22
 * Key technique: Find middle + Reverse second half
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //1找中点
        ListNode *slow = head, *fast = head;
        while(fast&&fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        //2.反转后半链表
        ListNode *prev = nullptr, *cur = slow;
        while(cur){
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        //3.比较是否回文链表
        ListNode *left = head, *right = prev;
        while(right)
        {
            if(left->val!=right->val)
                return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }
};
// @lc code=end

/*

// @lcpr case=start
// [1,2,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,2,1]\n
// @lcpr case=end

 */
