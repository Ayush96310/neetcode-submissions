class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord.size()!=endWord.size()) return 0;
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            auto [str,cnt] = q.front();
            q.pop();
            if(str==endWord) return cnt;
            for(int i=0; i<endWord.size();i++){
                string newWord = str;
                char original = newWord[i];
                for(int j=0; j<26; j++){
                    char nw = 'a'+j;
                    if(nw==original) continue;
                    newWord[i]=nw;
                    if(st.count(newWord)){
                        st.erase(newWord);
                        q.push({newWord,cnt+1});
                    }
                }
            }
        }
        return 0;
    }
};
