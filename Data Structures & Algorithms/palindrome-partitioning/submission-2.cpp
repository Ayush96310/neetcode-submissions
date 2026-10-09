
class Solution {
public:
    bool check(string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    void solve(string &s, vector<vector<string>>& ans,
               vector<string>& temp, int ind, int start) {
        if (ind == s.size() - 1) {
            if (check(s, start, ind)) {
                temp.push_back(s.substr(start, ind - start + 1));
                ans.push_back(temp);
                temp.pop_back();
            }
            return;
        }

        // TAKE: cut after index ind
        if (check(s, start, ind)) {
            temp.push_back(s.substr(start, ind - start + 1));

            solve(s, ans, temp, ind + 1, ind + 1);

            temp.pop_back();
        }

        // DON'T TAKE: don't cut here
        solve(s, ans, temp, ind + 1, start);
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        solve(s, ans, temp, 0, 0);

        return ans;
    }
};
