#include<iostream>
#include<cctype>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    int i=0;
    string x;
    int j=0;
    while(s[i]!='\0'){
        if(s[i]>='a' && s[i]<='z'){
            x[j]=s[i];
            cout<<x[j];
            j++;
        }
        else if(s[i]>='A' && s[i]<='Z'){
            x[j]=tolower(s[i]);
            cout<<x[j];
            j++;
        }
        i++;
    }

    cout<<x<<endl;
    int p1=0;
    int p2=x.length()-1;
    int flag =0;
    while(p1!=p2){
        if(x[p1]!=x[p2]){
            flag=1;
            break;
        }
        p1++;
        p2++;
    }
    if(flag==1){
        cout<<"false"<<endl;
    }
    else{
        cout<<"true"<<endl;
    }
}
