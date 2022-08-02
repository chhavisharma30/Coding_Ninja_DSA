//remove all x from the string

#include<iostream>
using namespace std;

void rmv(char s[]){
    if(s[0]=='\0'){
        return;
    }
    if(s[0] != 'x'){
        rmv(s+1);
    }
    else{
        int i=1;
        for(;s[i] != 0;i++){
            s[i-1]=s[i];
        }
        s[i-1]=s[i];
        rmv(s);
    }
}
int main(){
    char s[50];
    cin>>s;
    rmv(s);
    cout<<s<<endl;
}