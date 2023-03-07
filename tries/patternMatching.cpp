/*Given a  list of n words and a pattern p that we want to search. Check if the pattern p is present the given words or not. Return true if the pattern is present and false otherwise.
Input Format :
The first line of input contains an integer, that denotes the value of n.
The following line contains n space separated words.
The following line contains a string, that denotes the value of the pattern p.

Output Format :
The first and only line of output contains true if the pattern is present and false otherwise.

Constraints:
Time Limit: 1 sec

Sample Input 1 :
4
abc def ghi cba
de

Sample Output 2 :
true

Sample Input 2 :
4
abc def ghi hg
hi

Sample Output 2 :
true

Sample Input 3 :
4
abc def ghi hg
hif

Sample Output 3 :
false*/
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
        if(searchPattern(root,word)){
            return;
        }
        else{
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

    bool searchPattern(TrieNode* root, string word){
        //base case
        if(word.size()==0){
            return true;
        }

        //small calculation
        int index=word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            //pattern not found
            return false;
        }

        //recursive call
        return searchPattern(child,word.substr(1));
    }

    bool searchPattern(string word){
       return searchPattern(root,word);
    }

};

int main(){
    Trie t;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        t.insertWord(s);
        //inserting all possible suffices - making suffix trie
        for(int j=1;j<s.length();j++){
            t.insertWord(s.substr(j));
        }
    }
    string p;
    cin>>p;
    cout<<t.searchPattern(p)<<endl;
}
