//Check whether a given String S is a palindrome using recursion. Return true or false.


#include<iostream>
using namespace std;

bool ispal(string s,int start,int end){
    if(start==end){
        return true;
    }

    if(s[start] != s[end] ){
        return false;
    }

    if(start<end+1){
        return ispal(s,start+1,end-1);
    }

    return true;
}
bool ispalindrome(string s){
    int l = s.length();
    if(l==0){
        return true;
    }
    return ispal(s,0,l-1);
}

int main(){
    string s;
    cin>>s;
    cout<<ispalindrome(s)<<endl;
}