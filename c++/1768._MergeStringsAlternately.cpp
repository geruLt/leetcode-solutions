class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        if (word1 == "") {
            return word2;
        }
        else if (word2 == "") {
            return word1;
        }
        else {
            int shortstr = (word1.size() < word2.size()) ? word1.size() : word2.size();
            string str = "";

            for (int i = 0; i < shortstr; i++) {
                str = str + word1[i] + word2[i];
            }

            if (word1.size() < word2.size()) {
                str += word2.substr(shortstr, word2.size()-shortstr);
            }
            else {
                str += word1.substr(shortstr, word1.size()-shortstr);
            }
            return str;
        }
    }
};