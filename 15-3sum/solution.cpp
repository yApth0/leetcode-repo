#include <algorithm>
#include <climits>
#include <cstdlib>
#include <format>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result{};
        
        const int len{static_cast<int>(nums.size())};

        sort(nums.begin(), nums.end());
        
        int end{};
        for (int begin{}; begin < len - 2; ++begin)
        {
            if (begin > 0 && nums[begin] == nums[begin - 1]) continue;

            int middle{begin + 1};
            end = len - 1;

            while (middle < end)
            {
                int sum{nums[begin] + nums[middle] + nums[end]}; 

                if (sum == 0) 
                {
                    result.push_back({nums[begin], nums[middle], nums[end]});
                    ++middle;
                    --end;
                    while(end > middle && nums[middle] == nums[middle - 1]) ++middle;
                    while(end > middle && nums[end] == nums[end + 1]) --end;
                } 
                else if (sum < 0) middle++;
                else end--;
            }
        }
        return result;
    }
};

void print_result(vector<vector<int>> result)
{
    std::cout << '[';
    for (auto &r : result)
    {
        std::cout << '[';
        for (auto &n : r)
            std::cout << n << ',';
        std::cout << "], ";
    }
    std::cout << "]\n";
}

int main()
{
    vector<int> input{-1,0,1,2,-1,-4};

    Solution s;
    print_result(s.threeSum(input));

    input = {-100,-70,-60,110,120,130,160};
    print_result(s.threeSum(input));

    input = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    print_result(s.threeSum(input));

    input = {4,4,3,-5,0,0,0,-2,3,-5,-5,0};
    print_result(s.threeSum(input)); 

    input = {0,0,0,0};
    print_result(s.threeSum(input));

    input = {-10,-5,-5,-4,-4,-3,-2,-2,0,0,1,2,2,2,2,5,5};
    print_result(s.threeSum(input));
    return 0;
}

// [-4,-1,-1,0,1,2]

// [0,0,0,0,0,1,1,2]

// {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6}
