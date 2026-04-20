/*
 * @lc app=leetcode.cn id=24 lang=cpp
 * @lcpr version=30204
 *
 * [24] 两两交换链表中的节点
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
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        while (prev->next != nullptr&&  prev->next->next != nullptr)
        {
            ListNode *cur = prev->next;
            ListNode *n1 = cur->next;
            ListNode *n2 = n1->next;
            prev->next = n1;
            n1->next = cur;
            cur->next = n2;

            prev = cur;
        }
        return dummy->next;
    }
    /*
        递归交换
        递归交换链表中的节点，每次交换一对节点，返回新的头节点
    */
    // ListNode* swapPairs(ListNode* head) {
    //     if(head==nullptr||head->next==nullptr) return head;
    //     ListNode* next = head->next;
    //     head->next = swapPairs(next->next);
    //     next->next = head;
    //     return next;
    // }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
