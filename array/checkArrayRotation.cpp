/*You have been given an integer array/list(ARR) of size N. It has been sorted(in increasing order) and then rotated by some number 'K' in the clockwise direction.
Your task is to write a function that returns the value of 'K', that means, the index from which the array/list has been rotated.*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int flag=0;
    for(int i=0;i<n;i++){
        if(a[0]>a[i]){
            cout<<i<<endl;
            flag=1;
            break;
        }
    }
    if(flag==0){
        cout<<"0"<<endl;
    }
}

//we can also do this by using binary search