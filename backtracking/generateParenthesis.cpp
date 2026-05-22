#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void rec(int open, int close, string output, vector<string> &ans) {
        // BASE CASE: Both counts exhausted
        if (open == 0 && close == 0) {
            ans.push_back(output);
            return;
        }

        // CHOICE 1: Add Open Bracket
        // We can always add an open bracket as long as we have some left.
        if (open > 0) {
            rec(open - 1, close, output + '(', ans);
        }

        // CHOICE 2: Add Close Bracket
        // CRITICAL LOGIC: We can only add a closing bracket if we have 
        // MORE open brackets currently in the string than closing ones.
        // This means 'close' counter (remaining) must be greater than 'open' counter (remaining).
        if (close > open) {
            rec(open, close - 1, output + ')', ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        rec(n, n, "", ans);
        return ans;
    }
};

int main() {
    Solution sol;
    int n = 3; // Example input
    vector<string> result = sol.generateParenthesis(n);

    // PRINTING THE OUTPUT
    cout << "All combinations for n=" << n << ":" << endl;
    for (const string &s : result) {
        cout << s << endl;
    }

    return 0;
}