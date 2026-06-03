class TrieNode{
public:
    TrieNode* children[26];
    bool isEnd;
    TrieNode(){
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isEnd=false;
    }
};
class WordDictionary {
private:
    TrieNode* root;
    bool dfs(string& word, int pos, TrieNode* node) {
        if(pos == word.size()) {
            return node->isEnd;
        }

        char ch = word[pos];

        if(ch == '.') {
            for(int i = 0; i < 26; i++) {
                if(node->children[i] &&
                   dfs(word, pos + 1, node->children[i])) {
                    return true;
                }
            }
            return false;
        }

        int idx = ch - 'a';

        if(node->children[idx] == NULL) {
            return false;
        }

        return dfs(word, pos + 1, node->children[idx]);
    }
public:
    WordDictionary() {
        root=new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node=root;
        for(char ch:word){
            int indx=ch-'a';
            if(node->children[indx]==NULL){
                node->children[indx]=new TrieNode();
            }
            node=node->children[indx];
        }
        node->isEnd=true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};
