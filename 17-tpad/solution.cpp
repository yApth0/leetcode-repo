#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    map<char, string> keys{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void solveRecursive(string_view digits, vector<string>& result, string current="")
    {
        if (digits.size() < 1u)
        {
            result.push_back(current);
            return;
        }

        for (auto& letter : keys.at(digits[0]))
        {
            solveRecursive(digits.substr(1), result, current + letter);
        }
    }
    
    vector<string> letterCombinations(string digits) 
    {
        vector<string> result{};
        solveRecursive(digits, result);
        return result;
    }
};

int main()
{
    Solution s;
    cout << format("{}\n", s.letterCombinations("2377"));
    return 0;
}
