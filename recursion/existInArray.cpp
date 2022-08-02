//Given an array of length N and an integer x, you need to find if x is present in the array or not. Return true or false.
//Do this recursively.

#include<iostream>
using namespace std;

bool check(int arr[], int s, int no){
    if(s==0){
        return false;
    }

    if(arr[0]==no){
        return true;
    }
    bool exist = check(arr+1,s-1,no);
    if(exist){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    int n,num;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>num;
    cout<<check(a,n,num)<<endl;
}