class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int l=0, r=n-1;

        for(char& ch: s) ch = tolower(ch);
        
        while(l<r) {
            if(!isalpha(s[l]) && !isdigit(s[l])) {
                l++;
                continue;
            }
            if(!isalpha(s[r]) && !isdigit(s[r])) {
                r--;
                continue;
            }
            if(s[l] != s[r]) return 0;
            l++, r--;
        }
        return 1;
    }
};
