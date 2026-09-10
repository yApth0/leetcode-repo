#include <algorithm>
#include <format>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using Answer=vector<vector<int>>;
    Answer fourSum(vector<int>& nums, int target) {
        Answer answer;
        
        sort(nums.begin(), nums.end());
        
        const int length{static_cast<int>(nums.size())};
        for (int a{}; a < length - 3; ++a)
        {
            if (a > 0 && nums[a] == nums[a-1]) continue;

            int b{a + 1};
            int d{length - 1};
            int c{d - 1};

            // calc max
            const long long max_value{static_cast<long long>(nums[d]) + nums[c] + nums[c-1] + nums[c-2]};
            if (max_value < target) return answer;
            
            // calc min
            const long long min_value{static_cast<long long>(nums[a]) + nums[b] + nums[b+1] + nums[b+2]};
            if (min_value > target) return answer;

            while (b < c && c < d)
            {
                const long long sum{static_cast<long long>(nums[a]) + nums[b] + nums[c] + nums[d]};
                
                const bool comp{a != b && b != c && c != d};
                if (sum == target && comp)
                {
                    answer.push_back({nums[a], nums[b], nums[c], nums[d]});
                    ++b;
                    while (b < d && nums[b] == nums[b-1]) ++b;
                    --c;
                    while (c > a && nums[c] == nums[c+1]) --c;
                } 
                else if (sum > target) --c;
                else ++b;

                if (c <= b)
                {
                    --d;
                    while (d > a + 2 && nums[d] == nums[d+1]) --d;
                    b = a+1;
                    c = d-1;
                }
            }
        }

        return answer;
    }
};

void print_answer(vector<int> nums, int target)
{
    Solution s;
    cout << format("{}\n", s.fourSum(nums, target));
}

int main()
{
    print_answer({1,0,-1,0,-2,2}, 0);
    print_answer({2,2,2,2,2}, 8);
    print_answer({0,2,2,2,10,-3,-9,2,-10,-4,-9,-2,2,8,7}, 6);
    return 0;
}


// -10,-2,-3,-4,-9,-9,0,2,2,2,2,2,7,8,10

