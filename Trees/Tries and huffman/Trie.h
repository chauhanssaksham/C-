#include "TrieNode.h"
class Trie{
    TrieNode *root;
    void insertWord(TrieNode* root, string word){
        if (word.size() == 0){
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL){
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertWord(child, word.substr(1));
    }
    bool search(TrieNode* root, string word){
        if (word.size() == 0){
            return root->isTerminal;
        }
        int index = word[0] - 'a';
        if (root->children[index] == NULL){
            return false;
        }
        return search(root->children[index], word.substr(1));
    }
    TrieNode* removeWord(TrieNode* root, string word){
        if (word.size() == 0){
            root->isTerminal = false;
            for (int i=0; i<26; i++){
                if (root->children[i] != NULL){
                    return root;
                }
            }
            delete root;
            return NULL;
        }
        int index = word[0] - 'a';
        if (root->children[index] != NULL){
            root->children[index] = removeWord(root->children[index], word.substr(1));
            if (root->isTerminal){
                return root;
            }
            for (int i=0; i<26; i++){
                if (root->children[i] != NULL){
                    return root;
                }
            }
            delete root;
            return NULL;
        }
        return root;
    }
  public:
    Trie(){
        root = new TrieNode(NULL);
    }
    void insertWord(string word){
        insertWord(root, word);
    }
    bool search(string word) {
        // Write your code here
        return search(root, word);
    }
    void removeWord(string word){
        removeWord(root, word);
    }
};