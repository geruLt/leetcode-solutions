class Solution {
public:
    bool isPalindrome(int x) {
        string stringX = to_string(x);
        string stringXR =stringX;
        reverse(stringXR.begin(), stringXR.end());
        return (stringX == stringXR);
        }
};