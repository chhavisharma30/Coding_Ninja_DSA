/*Given an array of length N and an integer x, you need to find and return the last index of integer x present in the array. Return -1 if it is not present in the array.
Last index means - if x is present multiple times in the array, return the index at which x comes last in the array.
You should start traversing your array from 0, not from (N - 1).
Do this recursively. Indexing in the array starts from 0.*/


/*#include<iostream>
using namespace std;

int index(int arr[],int s,int num){
    if(s<0){
        return -1;
    }
    if(arr[s]==num){
        return s;
    }
    int temp = index(arr,s-1,num); 
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
}*/

//second method

#include<iostream>
using namespace std;

int index(int arr[],int s,int num){
    if(s<0){
        return -1;
    }
    int temp = index(arr+1,s-1,num);
    if(temp==-1){
        if(arr[0]==num){
            return 0;
        }
        else
            return -1;
    }
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