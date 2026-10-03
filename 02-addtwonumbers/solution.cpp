#include "../common/linkedlist.h"
#include <iostream>
#include <format>

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* sum = head;

        int carry{};
        while (l1 || l2 || carry)
        {
            int value{carry};
            if (l1)
            {
                value += l1->val;
                l1 = l1->next;
            }

            if (l2)
            {
                value += l2->val;
                l2 = l2->next;
            }
            sum->next = new ListNode(value%10);
            sum = sum->next;
            carry = value/10;
        }
        return head->next;
    }
};

int main()
{
    Solution s;
    ListNode* l1 = vector2nodes({9,9,9,9,9,9,9});
    ListNode* l2 = vector2nodes({9,9,9,9});
    std::cout << std::format("{}\n", nodes2vector(s.addTwoNumbers(l1,l2)));
    return 0;
}
