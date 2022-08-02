#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int main(){
    string s,t;
    cin>>s>>t;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    int i=0;
    int flag = 0;
    int len = 0;
    if(s.size()!=t.size()){
        cout<<"false"<<endl;
        return 0;
    }
    

    for(i=0;i<s.size();i++){
        if(s[i]!=t[i]){
            flag =1;
            break;
        }
    }
    if(flag==0 && s[i]=='\0' && t[i]=='\0'){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
}