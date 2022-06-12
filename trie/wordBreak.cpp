#include <bits/stdc++.h>
using namespace std;

class WordTrieNode {
public:
    WordTrieNode *next[26];
    bool isEnd;
    WordTrieNode() {
        for (int i = 0; i < 26; i++) {
            this -> next[i] = NULL;
        }
        this -> isEnd = false;
    }
};

class WordTrie {
public:
    WordTrieNode *root;
    WordTrie() {
        this -> root = new WordTrieNode();
    }

    void insert(string word) {
        WordTrieNode *curr = this -> root;

        for (auto ch: word) {
            int index = int(ch - 'a');
            if (curr -> next[index] == NULL) {
                curr -> next[index] = new WordTrieNode();
            } 
            curr = curr -> next[index];
        }
        curr -> isEnd = true;
    }

    bool isWordBreakablePresent (string &word, int stInd) {
        if (word.length() == 0) {
            return true;
        }

        WordTrieNode *curr = this -> root;
        for (int i = stInd; i < word.length(); i++) {
            int index = int(word[i] - 'a');
            if (curr -> next[index] == NULL) {
                return false;
            } 
            curr = curr -> next[index];
            if (curr -> isEnd and isWordBreakablePresent(word, i+1)) {
                return true;
            }
        }
        return curr -> isEnd;
    }
};

bool isWordBreak (vector < string > &dict, string inpStr) {
    WordTrie *root = new WordTrie();

    for (auto word: dict) {
        root -> insert(word);
    }

    return root -> isWordBreakablePresent(inpStr, 0);
}

int main () {
    vector < string > dict = {"mobile","samsung","sam",
                        "sung","ma\n","mango",
                        "icecream","and","go","i",
                        "like","ice","cream"};
    vector <string> inpts = {
        "ilikesamsung",
        "iiiiiiii",
        "",
        "ilikelikeimangoiii",
        "samsungandmango",
        "samsungandmangok"
    };
    for (auto inptWord: inpts) {
        cout << (isWordBreak(dict, inptWord) ? "Yes" : "No") << endl;
    }
}