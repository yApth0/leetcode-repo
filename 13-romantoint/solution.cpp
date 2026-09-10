#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    const map<char, int> roman_numbers
    {
        {'I', 1   },
        {'V', 5   },
        {'X', 10  },
        {'L', 50  },
        {'C', 100 },
        {'D', 500 },
        {'M', 1000}
    };

    int romanToInt(string s) {
        int total{};
        const int s_size{static_cast<int>(s.length())};
        
        for (int i{}; i < s_size; ++i)
        {
            const int current = roman_numbers.at(s[i]);

            if (i + 1 < s_size && current < roman_numbers.at(s[i+1]))
            {
                total += roman_numbers.at(s[i+1]) - current;
                ++i;
            }
            else
            {
                total += current;
            }
        }
        return total;
    }
};

int main()
{
    Solution s;
    cout << s.romanToInt("MMMDCCXLIX") << '\n';
    return 0;
}
