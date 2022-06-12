#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* next[27];
    bool isEnd;
    int subTrieCnt;
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            this -> next[i] = NULL;
        }
        this -> isEnd = false;
        this -> subTrieCnt = 0;
    }
};

class Trie {
public:
    TrieNode *root;
    Trie() {
        this -> root = new TrieNode();
    }

    void insertWord(string word) {
        TrieNode *curr = this -> root;
        for (auto ch: word) {
            int index = int(ch - 'a');
            cout << index << endl;
            curr -> subTrieCnt += 1;
            if (curr -> next[index] == NULL) {
                curr -> next[index] = new TrieNode();
            }
            curr = curr -> next[index];
        }
        curr -> isEnd = true;
    }

    void shortestUniquePrefixes (string currStr, TrieNode *curr, vector < string > &res) {
        if (curr == NULL) {
            curr = this -> root;
        }

        // base case
        if (curr -> subTrieCnt < 2) {
            res.push_back(currStr);
            return;
        }

        for (int i = 0; i < 26; i++) {
            if (curr -> next[i] != NULL) {
                shortestUniquePrefixes(currStr + char('a' + i), curr -> next[i], res);
            }
        }
    }

    int shortestUniquePrefixInd ( string word) {
        int cnt = 0;
        TrieNode *curr = this -> root;
        for (auto ch: word) {
            int index = int(ch - 'a');
            cnt++;
            curr = curr -> next[index];
            if (curr -> subTrieCnt < 2) {
                // cout << curr -> subTrieCnt << endl;
                return cnt;
            }
        } 
        return word.length();
    }
};

vector < string > shortestUniquePrefixes ( vector < string > inpStrs) {
    Trie *root = new Trie();
    for (auto word: inpStrs ) {
        // cout << word << endl;
        root -> insertWord(word);
    }

    vector < string > res;
    for (auto word: inpStrs ) {
        int length = root -> shortestUniquePrefixInd(word);
        cout << word << " " << length << endl;
        res.push_back(word.substr(0, length));
    }
    return res;
}

int main () {
    vector < string > inp = {"bearcat", "bert"};
    auto ans = shortestUniquePrefixes(inp);
    for (auto prefix : ans) {
        cout << prefix << endl;
    }
    return 0;
}