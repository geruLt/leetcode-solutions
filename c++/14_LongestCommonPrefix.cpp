class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        string comparer;
        for (int i = 1; i < strs.size(); i++) {
            comparer = strs[i];
            for (int j = prefix.size(); j > 0; j--) {
                if (j > comparer.size()) {
                    prefix.pop_back();
                }
                else if (prefix.substr(0,j) != comparer.substr(0,j)) {
                    prefix.pop_back();
                }
                else {
                    continue;
                }
            }
        }
        return prefix;
    }
};