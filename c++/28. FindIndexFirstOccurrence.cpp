class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack == needle) {
            return 0;
        }

        else if (haystack.size() < needle.size()) {
            return -1;
        }

        int needle_ = needle.size();
        for (int i = 0; i < haystack.size() - needle.size() + 1; i++) {
            cout << haystack.substr(i, needle_) << endl;
            if (haystack.substr(i, needle_) == needle) {
                return i;
            }
        }
        return -1;
    }
};