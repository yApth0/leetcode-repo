#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    const vector<char> roman_map
    {
        'I', 'V', 'X', 'L', 'C', 'D', 'M'
    };

    string intToRoman(int num) {
        string result{};
        
        int max_divisor{1000};
        while (num > 0)
        {
            if (num / max_divisor <= 0)
            {
                max_divisor /= 10;
                continue;
            }

            const int value{num / max_divisor};
            const int div{static_cast<int>(log10(max_divisor)) * 2};
            if (value == 9 || value == 4)
            {
                result += roman_map.at(div);
                result += roman_map.at(div + (value / 5) + 1);
            }
            else 
            {
                if (value >= 5)
                {
                    result += roman_map.at(div+1);
                }

                for (int i{}; i < value % 5; i++)
                    result.push_back(roman_map.at(div));
            }
            num -= (value * max_divisor);
            max_divisor /= 10;
        }
        return result;
    }

};

int main()
{
    Solution s;
    cout << s.intToRoman(3749) << endl;
    return 0;
}
