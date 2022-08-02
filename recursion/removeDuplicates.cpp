//Given a string S, remove consecutive duplicates from it recursively.

#include<iostream>
using namespace std;

void dupli(char s[]){
    if(s[0]=='\0'){
        return;
    }

    if(s[0] != s[1]){
        dupli(s+1);
    }
    else{
        int i=2;
        for(;s[i]!='\0';i++){
            s[i-1]=s[i];
        }
        s[i-1]=s[i];
        dupli(s);
    }
}

int main(){
    char s[50];
    cin>>s;
    dupli(s);
    cout<<s<<endl;
}