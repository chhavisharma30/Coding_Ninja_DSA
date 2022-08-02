//count no of digits in an integers

#include<iostream>
using namespace std;

int digits(int num){
    if(num<10){
        return 1;
    }
    int smalloutput = digits(num/10);
    smalloutput++;
    return smalloutput;
}

int main(){
    int n;
    cin>>n;
    cout<<digits(n)<<endl;
}