//Given a string, compute recursively a new string where all 'x' chars have been removed.

#include<iostream>
using namespace std;

string modified(string s){
    if(s.length()==0){
        return "";
    }

    if(s[0]=='x'){
        return modified(s.substr(1));
        }

    return s[0]+modified(s.substr(1));
}


int main(){
    string s;
    cin>>s;
    cout<<modified(s)<<endl;
}