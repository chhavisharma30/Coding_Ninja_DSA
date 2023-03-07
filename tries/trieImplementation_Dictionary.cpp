#include<iostream>
#include<string>
using namespace std;

class TrieNode{
    public:
    char data;      //data of the node
    TrieNode ** children;       //array that stores addresses of childern of node
    bool isTerminal;        //variable to decide whether a word ends at this letter or not

    TrieNode(char data){        //constructor
        this->data=data;
        children = new TrieNode*[26];
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    TrieNode * root;        //root of the trie
    public:
    Trie(){     //constructor
        root = new TrieNode('\0');
    }

    void insertWord(TrieNode *root , string word){
        //Base case
        if(word.size()==0){
            root->isTerminal=true;
            return;
        }

        //Small calculation
        int index=word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index]=child;
        }

        //Recursive call
        insertWord(child,word.substr(1));
    }

    void insertWord(string word){
        insertWord(root,word);
    }

    bool searchWord(TrieNode* root, string word){
        //Base case
        if(word.size()==0){
            return root->isTerminal;
        }

        //small calculation
        int index=word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            //word not found
            return false;
        }

        //recursive call
        return searchWord(child,word.substr(1));
    }

    bool searchWord(string word){
        return searchWord(root,word);
    }

    void removeWord(TrieNode* root, string word){
        //Base Case
        if(word.size()==0){
            root->isTerminal=false;
            return;
        }

        //Small Calculation
        int index = word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{
            //Wword not found
            return;
        }

        //Recursive call
        removeWord(child,word.substr(1));

        //Remove child node if it is useless
        if(child->isTerminal==false){
            for(int i=0;i<25;i++){
                if(child->children[i]!=NULL){
                    return;
                }
            }
            delete child;
            root->children[index]=NULL;
        }
    }

    void removeWord(string word){
        removeWord(root,word);
    }
};

int main(){
    Trie t;
    t.insertWord("and");
    t.insertWord("are");
    t.insertWord("dot");

    cout<<t.searchWord("and")<<endl;
    t.removeWord("and");
    cout<<t.searchWord("and")<<endl;
}
