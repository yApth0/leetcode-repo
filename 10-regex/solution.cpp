#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    map<pair<int,int>, bool> memo{};

    bool matchOne(char c, char p)
    {
        return c == p || p == '.';
    }

    bool matchRecursive(int i, int j, string_view s, string_view p)
    {
        const pair<int,int> ij(i,j);
        if (memo.contains(ij)) return false;

        const int ssize{static_cast<int>(s.length())};
        const int psize{static_cast<int>(p.length())};

        if (i >= ssize && j >= psize) return true;
        
        if (psize - j >= 2 && p.at(j + 1) == '*')
        {
            int tries{};
            while (tries <= ssize - i)
            {
                if (matchRecursive(i + tries, j + 2, s, p)) return true;
                if (i + tries == ssize || !matchOne(s.at(i + tries), p.at(j))) break;
                tries++;
            }
            memo.insert(make_pair(ij, true));
            return false;
        }

        if (ssize - i > 0 && psize - j > 0 && matchOne(s.at(i), p.at(j)))
            return matchRecursive(i + 1, j + 1, s, p);
        memo.insert(make_pair(ij, true));
        return false;
    }

    bool isMatch(string s, string p) 
    {
        memo.clear();
        return matchRecursive(0, 0, s, p);
    }
};

int main()
{
    Solution s;
    cout << boolalpha;
    cout << s.isMatch("aa",      "")        << '\n';
    cout << s.isMatch("",        "b*b")        << '\n';
    cout << s.isMatch("",        "a*b*")        << '\n';
    cout << s.isMatch("aa",      "a")        << '\n';
    cout << s.isMatch("aa",      "a*")       << '\n';
    cout << s.isMatch("bccca",   "bc*cca")     << '\n';
    cout << s.isMatch("abcdede", "ab.*de")   << '\n';
    cout << s.isMatch("aaa",     "ab*a*c*a") << '\n';
    cout << s.isMatch("aaca",    "b*aa*c*a") << '\n';
    cout << s.isMatch("a",       ".*..a*")   << '\n';
    cout << s.isMatch("ab",      ".*..")   << '\n';
    cout << s.isMatch("aab",     "b.*")   << '\n';
    cout << s.isMatch("aab",     "c*a*b")   << '\n';
    cout << s.isMatch("mississippi", "mis*is*p*.")   << '\n';
    return 0;
}

#ifdef BACKUP
    bool isMatch(string s, string p) {
        int sindex{}, pindex{};
        int ssize{static_cast<int>(s.length())};
        int psize{static_cast<int>(p.length())};
        char last_match{p.at(pindex)};

        while (sindex < ssize && pindex < psize)
        { 
            bool wildcard{last_match == '*'};
            if (!wildcard && p.at(pindex) != '.' && s.at(sindex) != p.at(pindex)) return false;
            else if (wildcard) while(s.at(sindex) == p.at(pindex)) ++sindex;
            last_match = p.at(pindex);
            pindex++;
            sindex+=!wildcard;
        }
        if (sindex < ssize || pindex < psize) return false;
        return true;
    }
#endif
