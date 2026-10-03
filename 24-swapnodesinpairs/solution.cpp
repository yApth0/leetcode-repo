#include "../common/linkedlist.h"
#include <iostream>
#include <format>

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head) return nullptr;
        
        if (!head->next)
            return head;

        ListNode* copy = head->next;
        ListNode* goal = copy->next;
        head->next->next = head;
        head->next = swapPairs(goal);
        return copy;
    }
};

int main()
{
    Solution s;
    ListNode* input{vector2nodes({1,2,3,4})};
    std::cout << std::format("{}\n", nodes2vector(s.swapPairs(input)));
}
