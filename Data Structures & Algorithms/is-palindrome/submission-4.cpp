class Solution {
public:
    bool valid(char c){
        if(('a'<=c && c<='z') || ('A'<=c && c<='Z') || ('0'<=c && c<='9')){
            return true;
        }
        return false;
    }
    char tolower(char c){
        if('A'<=c && c<='Z'){
            return c+32;
        }
        return c;
    }
    bool isPalindrome(string s) {
        int n = s.size();
        int i=0; int j=n-1;
        while(i<j){
            while(i<n && !valid(s[i])){
                i++;
            }
            while(j>=0 && !valid(s[j])){
                j--;
            }
            if(tolower(s[i])!=tolower(s[j])){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
