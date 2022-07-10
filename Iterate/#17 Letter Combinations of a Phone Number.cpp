class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> d_map = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        vector<string> ans;
        if(!digits.size()) return ans;
        ans.push_back("");
        for (int i = 0; i < digits.size(); i++) {
            vector<string> tmp;
            string letters = d_map[digits[i] - '0'];
            for (int j = 0; j < ans.size(); j++) {
                for (int k = 0; k < letters.size(); k++) {
                    tmp.push_back(ans[j] + letters[k]);
                }
            }
            tmp.swap(ans);
        }
        return ans;
    }
};class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> d_map = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        vector<string> ans;
        if(!digits.size()) return ans;
        ans.push_back("");
        for (int i = 0; i < digits.size(); i++) {
            vector<string> tmp;
            string letters = d_map[digits[i] - '0'];
            for (int j = 0; j < ans.size(); j++) {
                for (int k = 0; k < letters.size(); k++) {
                    tmp.push_back(ans[j] + letters[k]);
                }
            }
            tmp.swap(ans);
        }
        return ans;
    }
};
