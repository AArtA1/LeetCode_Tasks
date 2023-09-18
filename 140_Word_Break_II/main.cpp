class Solution {
public:
    void solve(vector <vector<string>> &arr, string s, int index, vector <string> &result) {
        if (index == 0) {
            result.emplace_back(s.substr(0, s.size() - 1));
            return;
        }
        for (auto it: arr[index]) {
            solve(arr, it + " " + s, index - it.size(), result);
        }
    }

    vector <string> wordBreak(string s, vector <string> &dict) {
        if (dict.empty()) return {};
        vector <vector<string>> strs(s.size() + 1);
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (dp[j]) {
                    string word = s.substr(j, i - j);
                    if (find(dict.begin(), dict.end(), word) != dict.end()) {
                        dp[i] = true;
                        strs[i].emplace_back(word);
                    }
                }
            }
        }
        vector <string> result;
        solve(strs, "", s.size(), result);
        return result;
    }
};