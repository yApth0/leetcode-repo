#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int n2{};
        for (ListNode* node{head}; node->next != nullptr; node = node->next, ++n2);
        n2 = abs(n2 - n + 1);
        
        if (n2 == 0) return head->next;
        ListNode* node{head};
        for (int i{}; i < n2 - 1; ++i) node = node->next;
        const ListNode* deletion{node->next};
        if (deletion && deletion->next != nullptr) node->next = deletion->next;
        else node->next = nullptr; 
        return head;
    }
};

ListNode* build_list(vector<int> numbers)
{
   if (numbers.empty()) return nullptr;

   ListNode* head = new ListNode(numbers[0]);
   ListNode* current = head;

   for (int index{1}; index < (int) numbers.size(); ++index)
   {
       current->next = new ListNode(numbers[index]);
       current = current->next;
   }
   return head;
}

int main()
{
    Solution s;
    s.removeNthFromEnd(build_list({1,2,3,4,5}), 2);
    return 0;
}
