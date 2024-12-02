class Solution {
public:
    int isPrefixOfWord(string sen, string word) {
        int m = word.size();
        int n = sen.size(), i = 0;

        int j = 0, wc = 1;
        while(i < n) {
            if(sen[i] == ' ') { wc++; i++; continue; } 
            while(i < n && j < m && sen[i] == word[j]) {
                j++; i++;
            }
            if(j == m) return wc;
            else {
                j = 0;
                while(i < n && sen[i] != ' ') i++;
            }
        }
        return -1;
    }
};