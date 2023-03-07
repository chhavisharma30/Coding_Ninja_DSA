/*Given n number of words and an incomplete word w. You need to auto-complete that word w.
That means, find and print all the possible words which can be formed using the incomplete word w.
Note : Order of words does not matter.
Input Format :
The first line of input contains an integer, that denotes the value of n.
The following line contains n space separated words.
The following line contains the word w, that has to be auto-completed.

Output Format :
Print all possible words in separate lines.

Constraints:
Time Limit: 1 sec

Sample Input 1 :
7
do dont no not note notes den
no

Sample Output 2 :
no
not
note
notes

Sample Input 2 :
7
do dont no not note notes den
de

Sample Output 2 :
den

Sample Input 3 :
7
do dont no not note notes den
nom

Sample Output 3 :
(Empty) There is no word which starts with "nom"*/
#include <iostream>
#include <string>
using namespace std;

class TrieNode
{
public:
    char data;           // data of the node
    TrieNode **children; // array that stores addresses of childern of node
    bool isTerminal;     // variable to decide whether a word ends at this letter or not

    TrieNode(char data)
    { // constructor
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
    TrieNode *root; // root of the trie
public:
    Trie()
    { // constructor
        root = new TrieNode('\0');
    }

    //func to insert word in trie
    void insertWord(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        insertWord(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertWord(root, word);
    }

    //func to search word in trie
    bool searchWord(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            return root->isTerminal;
        }

        // small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // word not found
            return false;
        }

        // recursive call
        return searchWord(child, word.substr(1));
    }

    bool searchWord(string word)
    {
        return searchWord(root, word);
    }

    //func to remove word from trie
    void removeWord(TrieNode *root, string word)
    {
        // Base Case
        if (word.size() == 0)
        {
            root->isTerminal = false;
            return;
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // Wword not found
            return;
        }

        // Recursive call
        removeWord(child, word.substr(1));

        // Remove child node if it is useless
        if (child->isTerminal == false)
        {
            for (int i = 0; i < 25; i++)
            {
                if (child->children[i] != NULL)
                {
                    return;
                }
            }
            delete child;
            root->children[index] = NULL;
        }
    }

    void removeWord(string word)
    {
        removeWord(root, word);
    }

    //func to search pattern from trie
    TrieNode *searchPattern(TrieNode *root, string word)
    {
        // base case
        if (word.size() == 0)
        {
            return root;
        }

        // small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // pattern not found
            return NULL;
        }

        // recursive call
        return searchPattern(child, word.substr(1));
    }

    TrieNode *searchPattern(string word)
    {
        return searchPattern(root, word);
    }

    //func to print all words present in trie
    void allPossibleWords(TrieNode *root, string word, string output)
    {   
        if (root->isTerminal == true)
        {
            cout << word + output << endl;
        }
        for (int i = 0; i < 25; i++)
        {
            if (root->children[i] != NULL)
            {
                TrieNode *child = root->children[i];
                allPossibleWords(child, word, output + child->data);
            }
        }
    }

    //function to print all possible words present with given prefix
    void autoComplete(TrieNode *root, string word)
    {   
        TrieNode *child = searchPattern(word);
        //pattern not found
        if (child == NULL)
        {
            return;
        }
        string output = "";
        //func to derive all possible words present with given suffix
        allPossibleWords(child, word, output);
    }

    void autoComplete(string word)
    {
        autoComplete(root, word);
    }
};

int main()
{
    Trie t;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        t.insertWord(s);
    }
    string w;
    cin >> w;
    t.autoComplete(w);
}
