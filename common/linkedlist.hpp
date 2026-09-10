#include <vector>

#if !defined(PITO_LINKEDLIST_H)
#define PITO_LINKEDLIST_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

static std::vector<int> nodes2vector(ListNode* head)
{
    std::vector<int> nums{};
    for (ListNode* current{head}; current != nullptr; current = current->next)
        nums.push_back(current->val);
    return nums;
}

static ListNode* vector2nodes(std::vector<int> nums)
{
    ListNode* head{new ListNode(nums[0])};
    ListNode* current = head;
    for (unsigned int i{1}; i < nums.size(); ++i)
    {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;
}

#endif
