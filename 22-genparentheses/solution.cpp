#include <cstdint>
#include <format>
#include <vector>
#include <iostream>
#include <string>

class Solution {
public:
    uint16_t get_next_iteration(const uint16_t value)
    {
        uint16_t idx{0b10u};
        uint16_t shift_amnt{0};
        uint16_t copy{value};
        while (copy > 0 && (copy & 0b11) != 2u) 
        {
            if ((idx & value) == 0) ++shift_amnt;
            copy >>= 1;
            idx <<= 1;
        }

        if (shift_amnt > 0) shift_amnt -= 1;
        if (copy == 0) return 0; // não achou nenhum 0b10

        const uint16_t next{static_cast<uint16_t>(value ^ (idx + (idx >> 1)))};
        const uint16_t pivot{static_cast<uint16_t>(~((idx >> 1) - 1))};
        return (next & pivot) | (value & ~pivot) << shift_amnt;
    }

    bool is_valid(uint16_t value, int n)
    {
        int balance{1}; // first (

        for (int i{}; i < n; ++i)
        {
            balance += (value & 1u) ? -1 : 1; 
            if (balance < 0) return false;
            value >>= 1;
        }
        balance += -1; // last )
        return balance == 0;
    }

    std::string value_to_string(uint16_t value, const int bit_count)
    {
        std::string result{'('};
        for (int i{}; i < bit_count; ++i)
        {
            const bool is_zero{static_cast<bool>((value & 1) == 1)};
            value >>= 1;
            result += is_zero ? ')' : '(';
        }
        return result + ')';
    }

    std::vector<std::string> generateParenthesis(int n) {
        if (!n) return {};
        std::vector<std::string> result;

        const int bit_count{2 * (n-1)};
        uint16_t builder = (static_cast<uint16_t>(1 << (n-1)) - 1) << (n-1);
        result.push_back(value_to_string(builder, bit_count));

        while ((builder = get_next_iteration(builder)) > 0)
        {
            
            if ((builder >> (bit_count - 2)) == 0) break;
            if (!is_valid(builder, bit_count)) continue;
            result.push_back(value_to_string(builder, bit_count));
        }
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

// 1100001 1010001  0001111 1010001
