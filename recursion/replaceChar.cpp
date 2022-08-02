//Given an input string S and two characters c1 and c2, you need to replace every occurrence of character c1 with character c2 in the given string.
//Do this recursively.

#include<iostream>
using namespace std;

void replace(char s[],char c1,char c2){
    if(s[0]=='\0'){
        return;
    }
    if(s[0] != c1){
        replace(s+1,c1,c2);
    }
    else{
        s[0]=c2;
        replace(s,c1,c2);
    }
}
int main(){
    char s[50];
    char c1,c2;
    cin>>s;
    cin>>c1>>c2;
    replace(s,c1,c2);
    cout<<s<<endl;
}