class Solution {
public:
    int romanToInt(string s) {
        int roman = 0;
        int sSize = s.size();
        for (int i = 0; i < sSize; i++) {
            if (s[i] == 'M') {
                roman += 1000;
            }
            else if (s[i] == 'D') {
                roman += 500;
            }
            else if (s[i] == 'L') {
                roman += 50;
            }
            else if (s[i] == 'V') {
                roman += 5;
            }
            else if (s[i] == 'C') {
                if (sSize > i) {
                    if (s[i+1] != 'D' && s[i+1] != 'M') {
                        roman += 100;
                    }
                    else {
                        roman -= 100;
                    }
                }
                else {
                    roman += 100;
                }
            }
            else if (s[i] == 'X') {
                if (sSize > i) {
                    if (s[i+1] != 'L' && s[i+1] != 'C') {
                        roman += 10;
                    }
                    else {
                        roman -= 10;
                    }
                }
                else {
                    roman += 10;
                }
            }
            else if (s[i] == 'I') {
                if (sSize > i) {
                    if (s[i+1] != 'V' && s[i+1] != 'X') {
                        roman += 1;
                    }
                    else {
                        roman -= 1;
                    }
                }
                else {
                    roman += 1;
                }
            }
        }
        return roman;
    }
};