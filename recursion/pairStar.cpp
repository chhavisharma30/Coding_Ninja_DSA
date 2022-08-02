//Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".
#include<iostream>
using namespace std;

void star(string& s, string& op,int i=0){
    op=op+s[i];

    if(i==s.length()-1){
        return;
    }

    if(s[i]==s[i+1]){
        op=op+ '*';
    }

    star(s,op,i+1);
}

int main(){
    string s;
    cin>>s;
    string op = "";
    star(s,op);
    cout<<op<<endl;
}