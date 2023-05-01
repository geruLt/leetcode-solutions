class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1) {
            return false;
        }
        else if (count(s.begin(), s.end(), '(') != count(s.begin(), s.end(), ')') ||
                 count(s.begin(), s.end(), '[') != count(s.begin(), s.end(), ']') ||
                 count(s.begin(), s.end(), '{') != count(s.begin(), s.end(), '}')) {
                     return false;
                 }
        else {
            while (s.size() > 0) {
                string checker = s;
                for (int i = 0; i < s.size(); i++) {
                    string sub = s.substr(i, 2);
                    if (sub == "()" || sub == "[]" || sub == "{}") {
                        s.erase(i, 2);
                        break;
                    }
                }
                if (checker == s) {
                    return false;
                }
            }
            return true;
            }
        }
};