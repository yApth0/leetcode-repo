#include "../common/linkedlist.h"
#include <format>
#include <iostream>
#include <vector>

class Solution {
public:
    using uint = unsigned int;
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if (lists.size() < 1)
            return nullptr;
        const int n{static_cast<int>(lists.size())};
        return merge_lists(0, n - 1, lists);
    }

    ListNode* merge_lists(int start, int end, std::vector<ListNode*>& lists)
    {
        if (start == end)
        {
            return lists[start];
        }

        int mid{start + (end - start) / 2};
        ListNode* left{merge_lists(start, mid, lists)};
        ListNode* right{merge_lists(mid+1, end, lists)};
        return merge(left, right);
    }

private:
    ListNode* merge(ListNode* a, ListNode* b)
    {
        ListNode* dummy{new ListNode()};
        ListNode* head = dummy;
        
        while (a && b)
        {
            if (a->val < b->val)
            {
                dummy->next = a;
                a = a->next;
            }
            else
            {
                dummy->next = b;
                b = b->next;
            }
            dummy = dummy->next;
        }

        dummy->next = a ? a : b;
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
