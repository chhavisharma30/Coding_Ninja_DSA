//Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in an array (in increasing order).
//Do this recursively. Indexing in the array starts from 0.

#include<iostream>
using namespace std;

int indexrecursive(int arr[], int s,int num,int output[]){
    if(s==0){
        return 0;
    }
    int smallop= indexrecursive(arr+1,s-1,num,output);

    if(arr[0]==num){
        for(int i=smallop-1;i>=0;i--){
            output[i+1]=output[i]+1;
        }

        output[0]=0;
        smallop++;
    }
    else{
        for(int i=smallop;i>=0;i--){
            output[i]=output[i]+1;
        }
    }
    return smallop;
}

int index(int ar[],int size,int no){
    int opt[size];
    int sz = indexrecursive(ar,size,no,opt);
    for(int i=0;i<sz;i++){
        cout<<opt[i]<<" ";
    }
}
int main(){
    int n,e;
    cin>>n;
    int a[n];
    int op[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>e;
    index(a,n,e);
}