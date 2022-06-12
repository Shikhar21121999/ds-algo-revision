#include <bits/stdc++.h>
using namespace std;

// trie node data structure
class TrieNode {
    public:
        TrieNode *next[26];
        bool isEnd;
    
    // initializer
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            this -> next[i] = nullptr;
        }
        this -> isEnd = false;
    }
};

class Trie {
    public:
        TrieNode *root;

    // initializer
    Trie() {
        this -> root = new TrieNode();
    }

    // insert a word into the trie
    void insert(string word) {
        TrieNode *curr = this -> root;

        for (auto ch: word) {
            int ind = ch - 'a';
            if (curr -> next[ind] == nullptr) {
                curr -> next[ind] = new TrieNode();
            }
            curr = curr -> next[ind];
        }
        curr -> isEnd = true;
    }

    void recur(TrieNode* curr, string word, vector < string > &res) {
        if (curr -> isEnd) {
            res.push_back(word);
        }

        for (int i = 0; i < 26; i++) {
            if (curr -> next[i] != nullptr) {
                string newWord = word + char('a' + i);
                recur(curr -> next[i], newWord, res);
            }
        }
    }

    // print words in the trie
    void printWords() {
        vector < string > res;
        string curr = "";

        for (int i = 0; i < 26; i++) {
            if (this -> root -> next[i] != nullptr) {
                string word = "";
                word += char('a' + i);
                recur(this -> root -> next[i], word, res);
            }
        }

        // print all the collected words
        for (auto word: res) {
            cout << word << endl;
        }
    }

};




int main () {
    // create a trie
    Trie *myTrie = new Trie();

    // add words to the trie
    myTrie->insert("shikhar");
    myTrie->insert("shoray");
    myTrie->insert("shiksha");

    myTrie->printWords();
}