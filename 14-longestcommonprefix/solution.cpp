#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)   
    {
        string result{};
        unsigned int index{};
        
        const int len{static_cast<int>(strs.size())};
        
        auto limit{strs.at(0).length()};
        for(int i{1}; i < len; ++i)
            if (strs.at(i).length() < limit) limit = strs.at(i).size();

        while (index < limit)
        {
            const char pattern{strs.back()[index]};
            for (int i{len - 1}; i >= 0; --i)
            {
                if (strs.at(i)[index] != pattern) return result;
            }
            result += pattern;
            ++index;
        }
        return result;
    }
};

int main()
{
    vector<string> input{"flower", "flow", "flight"};
    Solution s;
    cout << s.longestCommonPrefix(input) << std::endl;
    return 0;
}
