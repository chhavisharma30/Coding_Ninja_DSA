/*For a given expression in the form of a string, find the minimum number of brackets that can be reversed in order to make the expression balanced. 
The expression will only contain curly brackets.
If the expression can't be balanced, return -1.
Example:
Expression: {{{{
If we reverse the second and the fourth opening brackets, the whole expression will get balanced. 
Since we have to reverse two brackets to make the expression balanced, the expected output will be 2.

Expression: {{{
In this example, even if we reverse the last opening bracket, we would be left with the first opening bracket and 
hence will not be able to make the expression balanced and the output will be -1.

Input Format :
The first and the only line of input contains a string expression, without any spaces in between.

Output Format :
The only line of output will print the number of reversals required to balance the whole expression. Prints -1, otherwise.*/

#include<iostream>
#include<stack>
using namespace std;

//function that returns minimum no of reversals required
int minReverse(string s){

    //if string length is odd then return -1
    if(s.length()%2!=0){
        return -1;
    }

    else{

        //make a stack to store string characters
        stack<char> temp;

        for(int i=0;i<s.length();i++){

            //if it is a opening bracket, simply push it into stack
            if(s[i]=='{'){
                temp.push(s[i]);
            }

            //if it is closing bracket, if stack is empty or top is also a closing bracket then push the character, otherwise pop from stack
            else if(s[i]=='}'){
                if(temp.empty()){
                    temp.push(s[i]);
                }
                else if(!temp.empty() && temp.top()=='{'){
                    temp.pop();
                }
                else{
                    temp.push(s[i]);
                }
            }
        }

        //initialize a variable to store count of reversals
        int count=0;

        //if stack is empty after string traversal then it is already balanced so return 0
        if(temp.empty()){
            return 0;
        }
        else{

            // if stack is not empty then while stack is not empty pop two charcters from stack and compare them
            while(!temp.empty()){
            char t1 = temp.top();
            temp.pop();
            char t2= temp.top();
            temp.pop();

            //if both brackets are same then increment count by 1otherwise if both are different increment count by 2( this case : }{ )
            if(t1==t2){
                count++;
            }
            else{
                count=count+2;
            }
            }
        }

        return count;
    }
}

int main(){
    string s;
    cin>>s;
    int reversals = minReverse(s);
    cout<<reversals<<endl;
}