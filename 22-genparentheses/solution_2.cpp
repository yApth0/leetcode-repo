#include <string>
#include <vector>
#include <iostream>
#include <format>

class Solution
{
public:
    // (open, closed, &result)
    void backtrack(std::string builder, int open, int closed, int n, std::vector<std::string>& result)
    {
        if (open + closed == 2 * n)
        {
            result.push_back(builder);
            return;
        }

        if (open < n)
            backtrack(builder + '(', open + 1, closed, n, result);

        if (closed < open)
            backtrack(builder + ')', open, closed + 1, n, result);
    }

    std::vector<std::string> generateParenthesis(int n)
    {
        std::vector<std::string> result;
        backtrack("", 0, 0, n, result);
        return result;
    }
};

int main()
{
    Solution s;
    for (int n{}; n < 9; ++n)
        std::cout << std::format("{}\n", s.generateParenthesis(n));
    return 0;
}
