#include <format>
#include <vector>
#include <unordered_map>
#include <iostream>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> seen{};
        
        const int n{static_cast<int>(nums.size())};
        for (int idx{}; idx < n; ++idx)
        {
            if (seen.contains(nums[idx]))
            {
                return {idx, seen.at(nums[idx])};
            }
            const int sub{target - nums[idx]};
            seen.insert({sub, idx});
        }
        return {};
    }
};

int main()
{
    Solution s;
    std::vector<int> nums{3,2,4};
    std::cout << std::format("{}\n", s.twoSum(nums,6));
    return 0;
}
