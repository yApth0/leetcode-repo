#include <iostream>
#include <vector>
#include <format>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::vector<char> opened{};

        for (auto &c : s)
        {
            if (c == '{' || c == '[' || c == '(')
            {
                opened.push_back(c);
            }
            else
            {
                const char opposite{static_cast<char>(c == ')' ? c - 1 : c - 2)};
                if (opened.back() == opposite) opened.pop_back();
                else return false;
            }
        }

        if (!opened.empty()) return false;
        return true;
    }
};

int main()
{
    Solution s;
    std::cout << std::boolalpha;
    std::cout << s.isValid("]") << '\n';
    return 0;
}
