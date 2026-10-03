#include "../common/linkedlist.h"
#include <format>
#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    using uint = unsigned int;
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        ListNode* head = new ListNode();
        auto dummy = head;

        const int n{static_cast<int>(lists.size())};
        std::priority_queue<int, std::vector<int>, std::greater<int>> builder{};

        if (!n) 
            return nullptr;
        
        for (uint i{}; i < lists.size(); ++i)
        {
            while (lists[i])
            {
                builder.push(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }

        while (!builder.empty())
        {
            dummy->next = new ListNode(builder.top());
            dummy = dummy->next;
            builder.pop();
        }

        return head->next;
    }
};

int main()
{
    Solution s;

    std::vector<ListNode*> nodes;
    nodes.push_back(vector2nodes({1,4,5}));
    nodes.push_back(vector2nodes({1,3,4}));
    nodes.push_back(vector2nodes({6}));

    std::cout << std::format("{}\n", nodes2vector(s.mergeKLists(nodes)));
    return 0;
}
