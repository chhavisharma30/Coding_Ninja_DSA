/*Given two string s and t, write a function to check if s contains all characters of t (in the same order as they are in string t).
Return true or false.
Do it recursively.
E.g. : s = “abchjsgsuohhdhyrikkknddg” contains all characters of t=”coding” in the same order. So function will return true.
Input Format :
Line 1 : String s
Line 2 : String t

Output Format :
true or false*/

#include<iostream>
#include<cstring>
using namespace std;

//function to check if the required string is contained by given string in the same order
bool checkString(string s,string s1){
    int i=0;
    int j=0;
    while(s[i]!='\0' && s1[j]!='\0'){
        if(s[i]==s1[j]){
            j++;
        }
        i++;
    }
    if(j==s1.length()){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string s;
    cin>>s;
    string s1;
    cin>>s1;
    bool ans = checkString(s,s1);
    cout<<ans<<endl;
}