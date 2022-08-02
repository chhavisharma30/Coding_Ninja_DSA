//Given an array of length N and an integer x, you need to find and return the first index of integer x present in the array. Return -1 if it is not present in the array.
//First index means, the index of first occurrence of x in the input array.
//Do this recursively. Indexing in the array starts from 0.


#include<iostream>
using namespace std;

int index(int arr[],int s,int num){
    if(s<0){
        return -1;
    }
    if(arr[0]==num){
        return 0;
    }
    int temp = index(arr+1,s-1,num);
    if(temp==-1)
        return -1;
    else  
        return temp+1;  
}

int main(){
    int n,e;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>e;
    cout<<index(a,n,e)<<endl;
}