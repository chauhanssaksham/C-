#include <iostream>
#include <string>
using namespace std;
#include "Trie.h"

int main(){
    string word;
    Trie dict;
    int choice;
    cout << "Enter a choice: " << endl;
    cin >> choice;
    while(choice != -1){
        if (choice == 1){
            //Insert Word
            cout << "Insert a word" << endl;
            cin >> word;
            dict.insertWord(word);
        } else if (choice == 2){
            cout << "Find a word" << endl;
            cin >> word;
            if (dict.search(word)){
                cout << "Present" << endl;
            } else {
                cout << "Not present" << endl;
            }
        } else {
            cout << "Remove a word" << endl;
            cin>> word;
            dict.removeWord(word);
        }
        cout << "Enter a choice: " << endl;
        cin >> choice;
    }

    return 0;
}