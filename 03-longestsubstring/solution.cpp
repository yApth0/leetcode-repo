#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        const int n{static_cast<int>(s.size())};

        if (!n)
            return 0;

        int start{};
        int end{1};
        
        std::unordered_map<char, int> seen{{s[start], start}};

        int longest{1};
        int new_start{};
        for (; end < n; ++end)
        {
            const char letter{s[end]};
            auto element{seen.find(letter)};

            if (element == seen.end())
            {
                element = seen.insert({letter, end}).first;
            }
            
            if (element->second < end)
            {
                new_start = std::max(new_start, element->second + 1);
                start = new_start;
            }
            
            element->second = end;

            longest = std::max(longest, end - start + 1);
        }
            
        return longest;
    }
};

int main()
{
    Solution s;
    std::cout << s.lengthOfLongestSubstring("abcabcbb") << '\n';
    std::cout << s.lengthOfLongestSubstring("pwwkew") << '\n';
    std::cout << s.lengthOfLongestSubstring("aaaaaa") << '\n';
    std::cout << s.lengthOfLongestSubstring("S") << '\n';
    std::cout << s.lengthOfLongestSubstring("edd") << '\n';
    std::cout << s.lengthOfLongestSubstring("kbdbl") << '\n';
    std::cout << s.lengthOfLongestSubstring("abccde") << '\n';
    std::cout << s.lengthOfLongestSubstring("mq") << '\n';
    std::cout << s.lengthOfLongestSubstring("ccbbcc") << '\n';
    return 0;
}
