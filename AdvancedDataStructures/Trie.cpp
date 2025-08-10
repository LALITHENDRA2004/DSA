#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    vector<Node*> links;
    bool flag;

    Node() {
        links.resize(26, NULL);
        flag = false;
    }
};

class Trie {
    private:
        Node *root;

    public:
        Trie() {
            root = new Node();
        }

        void insertWord(string s) {
            Node *node = root;
            for(int i = 0 ; i < s.size() ; i++) {
                if(node -> links[s[i] - 'a'] == NULL) {
                    node -> links[s[i] - 'a'] = new Node(); 
                }
                node = node -> links[s[i] - 'a'];
            }
            node -> flag = true;
        }

        bool searchWord(string& word) {
            Node* node = root;
            for(int i = 0 ; i < word.size() ; i++) {
                char ch = word[i];
                if(node -> links[ch - 'a'] == NULL) {
                    return false; 
                }
                node = node -> links[ch - 'a'];
            }
            return node -> flag;
        }

        void displayWord(Node *node, string& word) {
            if(node -> flag == true) {
                cout << word << endl;
            }

            for(int i = 0 ; i < 26 ; i++) {
                if(node -> links[i] != NULL) {
                    word.push_back('a' + i);
                    displayWord(node -> links[i], word);
                    word.pop_back();
                }
            }
        }

        void display() {
            string word = "";
            displayWord(root, word);
        }

};

int main() {
    int n;
    cout << "Enter the number of operations: ";
    cin >> n; 

    Trie trie1;

    while(n--) {
        cout << "Operations: " << endl;
        cout << "1. Insert word" << endl;
        cout << "2. Search word" << endl; 
        cout << "3. Search prefix" << endl;
        cout << "4. Display words" << endl;

        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1: {
            string word;
            cout << "Enter the word to be inserted: ";
            cin >> word;
            trie1.insertWord(word);
            break;
        }
        case 2: {
            string word;
            cout << "Enter the word to be searched: ";
            cin >> word;
            trie1.searchWord(word);
            break;
        }
        case 3: {
            string prefix;
            cout << "Enter the prefix to be searched: ";
            cin >> prefix;
            trie1.insertWord(prefix);
            break;
        }
        case 4:
            trie1.display();
            break;
        default:
            cout << "Enter a valid choice...";
        }
    }

    trie1.display();

    // string word = "abdf";
    // bool flag = trie1.searchWord(word);
    // cout << flag;
    return 0;
}