//Given an array of length N, you need to find and return the sum of all elements of the array.
//Do this recursively.

#include<iostream>
using namespace std;

int sum(int arr[],int s){
    if(s==1){
        return arr[0];
    }
    int so = sum(arr+1,s-1);
    so = so + arr[0];
    return so;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<sum(a,n)<<endl;
}