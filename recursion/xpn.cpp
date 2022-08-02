//Write a program to find x to the power n (i.e. x^n). Take x and n from the user. You need to return the answer.
//Do this recursively.

#include<iostream>
using namespace std;

int pow(int a,int b){
    if(b==1){
        return a;
    }
    int smalloutput=pow(a,b-1);
    int output=smalloutput*a;
    return output;
}

int main(){
    int x,n;
    cin>>x>>n;
    cout<<pow(x,n)<<endl;
}