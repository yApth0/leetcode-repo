#include "../common/linkedlist.h"
#include <iostream>

class Solution
{
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode* dummy = new ListNode(0, head);
        ListNode* previous = dummy;
        ListNode* curr = head;

        while (curr && curr->next)
        {
            ListNode* last = curr;
            for (int idx{}; idx < k - 1; ++idx)
            {
                if (!last->next) return dummy->next;
                last = last->next;
            }
            
            ListNode* goal = last->next;
            ListNode* bt = goal;
            previous->next = last;
            previous = curr;
            while (curr != goal)
            {
                ListNode* front = curr->next;
                curr->next = bt;
                bt = curr;
                curr = front;
            }
        }

        return dummy->next;
    }
};

int main()
{
    Solution s;
    ListNode* input{vector2nodes({1,2,3,4,5,6,7})};
    std::cout << printable_nodes(s.reverseKGroup(input, 3));
    
    ListNode* input2{vector2nodes({1,2,3,4,5,6,7,8,9,10})};
    std::cout << printable_nodes(s.reverseKGroup(input2, 5));

    return 0;
}
