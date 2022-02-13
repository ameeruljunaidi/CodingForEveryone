#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::string;
using std::vector;

class Solution
{
  public:
    static bool wordBreak(const string &s, const vector<string> &wordDict)
    {
        string copy = s;

        for (const string &word : wordDict)
        {
            if (copy.empty()) return true;
            if (copy.find(word))
            {
                copy = copy.substr(s.find(word) + word.length());
            }

        }

        return false;
    }
};

int main()
{
    vector<string> wordDict = {"leet", "code"};
    string s = "leetcode";
    bool answer = Solution::wordBreak(s, wordDict);
    cout << answer << "\n";
}