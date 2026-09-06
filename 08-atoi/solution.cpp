#include <cctype>
#include <climits>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int value{}, index{};

        const int length{static_cast<int>(s.length())}; 

        while (index < length && isspace(s[index])) ++index;
        if (index >= length) return value;

        int sign{(s[index] == '-') ? -1 : 1};
        if (s[index] == '-' || s[index] == '+') ++index;
        if (index >= length) return value;

        while (index < length && isdigit(s[index])) 
        {
            int digit{(s[index] - '0') * sign};
            if (sign == -1 && value < (INT_MIN - digit) / 10)
                return INT_MIN;
            else if (sign == 1 && value > (INT_MAX - digit) / 10)
                return INT_MAX;
            value = (value * 10) + digit;
            ++index;
        }
        return value;
    }
};

int main()
{
    Solution s;
    cout << s.myAtoi("42") << '\n';
    cout << s.myAtoi(" \n-00543.abc") << '\n';
    cout << s.myAtoi("-2147483888") << '\n';
    return 0;
}
