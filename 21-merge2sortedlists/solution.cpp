#include <iostream>
#include <format>
#include "../common/linkedlist.hpp"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* builder = new ListNode(0);
        ListNode* head = builder;

        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                builder->next = new ListNode(list1->val);
                list1 = list1->next;
            }
            else
            {
                builder->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            builder = builder->next;
        }

        builder->next = list1 ? list1 : list2;
        delete builder;
        return head->next;
    }
};

int main()
{
    Solution s;
    ListNode* a{vector2nodes({1,2,4})};
    ListNode* b{vector2nodes({1,3,4})};
    std::cout << std::format("{}", nodes2vector(s.mergeTwoLists(a,b)));
    return 0;
}
