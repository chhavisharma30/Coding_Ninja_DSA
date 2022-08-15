/*For a given a string expression containing only round brackets or parentheses, check if they are balanced or not. Brackets are said to be balanced if the bracket which opens last, closes first.
Example:
Expression: (()())
Since all the opening brackets have their corresponding closing brackets, we say it is balanced and hence the output will be, 'true'.

You need to return a boolean value indicating whether the expression is balanced or not.
Note:
The input expression will not contain spaces in between.

Input Format:
The first and the only line of input contains a string expression without any spaces in between.

Output Format:
The only line of output prints 'true' or 'false'.
*/
#include<iostream>
#include<stack>
using namespace std;

bool balanced(string s){

    //make a stack to store the string characters
    stack<char> st;

    //traversing the string
    for(int i=0;i<s.length();i++){

        //if character is an opening bracket, then push it into the stack
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
        }

        //if it is closing bracket and its matching opening bracket is at the top and stack is not empty then pop character from stack
        else if(!st.empty() && ((s[i]==')' && st.top()=='(') || (s[i]=='}' && st.top()=='{') || (s[i]==']' && st.top()=='[')) ){
            st.pop();
        }

        //if matching bracket is not found then return false
        else{
            return false;
        }
    }

    //if stack is empty at last then return true otherwise return false
    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string s;
    getline(cin,s);
    if(balanced(s)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
}