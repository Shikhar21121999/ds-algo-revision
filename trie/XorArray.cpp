#include <bits/stdc++.h>
using namespace std;

class BinaryTrieNode {
public:
    BinaryTrieNode *next[2];
    BinaryTrieNode() {
        next[0] = NULL;
        next[1] = NULL;
    }
};

class BinaryTrie{
public:
    BinaryTrieNode *root;
    BinaryTrie() {
        this -> root = new BinaryTrieNode();
    }

    // construction of binaryTire
    void insertNum (int num) {
        BinaryTrieNode* curr = this -> root;
        for(int i = 31; i >= 0; i--) {
            int index = (num >> i) & 1;
            if (curr -> next[index] == NULL) {
                curr -> next[index] = new BinaryTrieNode();
            }
            curr = curr -> next[index];
        }
    }

    int getXor (int num) {
        int res = 0;
        BinaryTrieNode* curr = this -> root;

        for(int i = 31; i >= 0; i--) {
            int index = (num >> i) & 1 ? 0 : 1;
            if (curr -> next[index] != NULL) {
                res = res << 1;
                res |= 1;
                curr = curr -> next[index];
            } else {
                res = res << 1;
                res |= 0;
                curr = curr -> next[!index];
            }
        }
        return res;
    }
};
int solve(vector<int> &A, vector<int> &B) 
{
    BinaryTrie *root = new BinaryTrie();
    for (auto x: A) {
        root -> insertNum(x);
    }

    int maxAns = 0;
    for (auto x: B) {
        maxAns = max(maxAns, root -> getXor(x));
    }

    return maxAns;
}
