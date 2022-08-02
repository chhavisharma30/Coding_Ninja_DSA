//find length of given string

#include<iostream>
using namespace std;

int length(char s[]){
    if(s[0]=='\0'){
        return 0;
    }
    int smalllength=length(s+1);
    return 1+smalllength;
}

int main(){
    char s[50];
    cin>>s;
    cout<<length(s)<<endl;
}