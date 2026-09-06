#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int max_score{};
        int i{};
        int j{static_cast<int>(height.size() - 1)};

        while (i < j)
        {
            const int score{min(height[i], height[j]) * abs(i-j)};
            if (score > max_score)
            {
                max_score = score;
            }

            if (height[i] - height[j] < 0) ++i;
            else if (height[j] - height[i] < 0) --j;
            else {++i;--j;}
        }
        return max_score;
    }
};

int main()
{
    vector<int> solve{1,8,6,2,5,4,8,3,7};
    Solution s;
    cout << s.maxArea(solve) << '\n';

    solve = {8,7,2,1};
    cout << s.maxArea(solve) << '\n';

}
