//print all subsequences of given string. subsequence = all possible combination of characters
#include<iostream>
#include<cmath>
using namespace std;

int subs(string s, string output[]){
    if(s.empty()){
        output[0]="";
        return 1;
    }

    int smallopsize=subs(s.substr(1),output);
    for(int i=0;i<smallopsize;i++){
        output[smallopsize+i]=s[0]+output[i];
    }
    return 2*smallopsize;
}

int main(){
    string s;
    cin>>s;
    int l = s.length();
    int sz = pow(2,l);
    string* output = new string[sz];
    int size = subs(s,output);
    for(int i=0;i<size;i++){
        cout<<output[i]<<endl;
    }
}