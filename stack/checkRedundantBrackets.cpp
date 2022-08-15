/*For a given expression in the form of a string, find if there exist any redundant brackets or not. 
It is given that the expression contains only rounded brackets or parenthesis and the input expression will always be balanced.
A pair of the bracket is said to be redundant when a sub-expression is surrounded by unnecessary or needless brackets.
Example:
Expression: (a+b)+c
Since there are no needless brackets, hence, the output must be 'false'.

Expression: ((a+b))
The expression can be reduced to (a+b). Hence the expression has redundant brackets and the output will be 'true'.
*/
#include<iostream>
#include<stack>
using namespace std;

bool checkBraces(string s){

    stack<char> temp;

    for(int i=0;i<s.length();i++){

        if(s[i]==')'){

            char top=temp.top();
           temp.pop();
           bool flag=true;

           while(!s.empty()&& top!='('){
            if (top == '+' || top == '-' ||top == '*' || top == '/')
                    flag = false;

            top = temp.top();
            temp.pop();
           }

           if(flag==true){
            return true;
           }
        }
        else{
            temp.push(s[i]);
        }
    }

    return false;
}

int main(){
    string s;
    cin>>s;
    cout<<checkBraces(s)<<endl;
}