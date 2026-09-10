#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest{(int)10e4};

        sort(nums.begin(), nums.end());

        const int length{static_cast<int>(nums.size())};

        for(int begin{}; begin < length - 2; ++begin)
        {
            if (begin > 0 && nums[begin] == nums[begin-1]) continue;

            int middle{begin + 1};
            int end{length - 1};

            while (middle < end)
            {
                const int sum{nums[begin] + nums[middle] + nums[end]};

                if (sum == target) return target;
                else if (sum < target) 
                {
                    ++middle;
                    while(end > middle && nums[middle] == nums[middle - 1]) ++middle;
                }
                else 
                {
                    --end;
                    while(end > middle && nums[end] == nums[end + 1]) --end;
                }

                if (abs(sum - target) < abs(closest - target)) closest = sum;
            }
        }
        return closest;
    }
};

int main()
{
    Solution s;
    vector<int> input{-1,2,1,-4};
    cout << s.threeSumClosest(input, 1) << '\n';
    return 0;
}
