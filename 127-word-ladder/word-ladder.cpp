class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      unordered_set wordSet(wordList.begin(),wordList.end());
        if(wordSet.find(endWord)==wordSet.end()){return 0;}
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        wordSet.erase(beginWord);
        while (!q.empty()) {
            auto [word, length] = q.front();
            q.pop();
            for(int i=0;i<word.length();i++){
                char original=word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(word==endWord){
                        return length+1;
                    }
                    if(wordSet.find(word)!=wordSet.end()){
                        q.push({word,length+1});
                        wordSet.erase(word);
                    }
                }
                word[i]=original;
            }}
        return 0;
    }
};