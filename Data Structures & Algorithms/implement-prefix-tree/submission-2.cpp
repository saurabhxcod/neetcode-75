class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isEnd = false;
    }
};

class PrefixTree {
private:
    TrieNode* root;

public:
    PrefixTree() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;

        for(char ch : word) {
            int indx = ch - 'a';

            if(node->children[indx] == NULL) {
                node->children[indx] = new TrieNode();
            }

            node = node->children[indx];
        }

        node->isEnd = true;
    }

    bool search(string word) {
        TrieNode* node = root;

        for(char ch : word) {
            int indx = ch - 'a';

            if(node->children[indx] == NULL) {
                return false;
            }

            node = node->children[indx];
        }

        return node->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;

        for(char ch : prefix) {
            int indx = ch - 'a';

            if(node->children[indx] == NULL) {
                return false;
            }

            node = node->children[indx];
        }

        return true;
    }
};