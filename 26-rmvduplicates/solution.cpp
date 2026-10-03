#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int k = nums.size();

        for (int idx{k-1}; idx > 0; --idx)
        {
            while (idx > 0 && nums[idx-1] == nums[idx])
            {
                nums.erase(nums.begin() + idx--);
                --k;
            }

        }
        return k;
    }
};

int main()
{
    Solution s;
    std::vector<int> input{0,0,1,1,1,2,2,3,3,4};
    std::cout << std::format("k = {}, nums = {}\n", s.removeDuplicates(input), input);

    input = {1,1};
    std::cout << std::format("k = {}, nums = {}\n", s.removeDuplicates(input), input);
    return 0;
}
