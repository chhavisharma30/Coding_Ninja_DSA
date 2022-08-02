//Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".

#include<iostream>
#include<string.h>
using namespace std;

string replacePi(string s){
    if(s.length()==0||s.length()==1){
        return s;
    }
    if(s[0]=='p'&&s[1]=='i'){
        string smallop=replacePi(s.substr(2));
        return "3.14"+smallop;
    }
    else{
        return s[0]+replacePi(s.substr(1));
    }

}
int main(){
    string s;
    cin>>s;
    string res = replacePi(s);
    cout<<res<<endl;
}