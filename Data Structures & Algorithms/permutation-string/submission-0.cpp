class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n2<n1) return false;
        string hash1(26,'0');
        for(char c:s1){
            hash1[c-'a']++;            
        }
        string hash2(26,'0');
        for(int i=0; i<n1;i++){
            hash2[s2[i]-'a']++;
        }
        if(hash2==hash1) return true;
        for(int i=n1;i<n2;i++){
            hash2[s2[i]-'a']++;
            hash2[s2[i-n1]-'a']--;
            if(hash1==hash2) return true;
        }
        return false;
    }
};
