#include<iostream>
using namespace std;

void permute(string s, string op){
    if(s.empty()){
        cout<<op<<endl;
        return;
    }
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        string left = s.substr(0,i);
        string right = s.substr(i+1);
        string rest = left+right;
        permute(rest,op+ch);
    }

}

int main(){
    string s;
    cin>>s;
    string op ="";
    permute(s,op);
}