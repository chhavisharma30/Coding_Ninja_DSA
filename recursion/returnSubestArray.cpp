/*Given an integer array (of length n), find and return all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.*/

#include<iostream>
using namespace std;

int subset(int a[],int n,int op[][100]){
    if(n==0){
        op[0][0]=0;
        return 1;
    }
    int smallop=subset(a+1,n-1,op);

    for(int i=0;i<smallop;i++){
        op[i+smallop][0]=op[i][0]+1;
        op[i+smallop][1]=a[0];
        for(int j=0;j<op[i][0];j++){
            op[i+smallop][j+2]=op[i][j+1];
        }
    }
    return 2*smallop;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int op[1000][100];
    int size=subset(a,n,op);

    for(int i=0;i<size;i++){
        for(int j=1;j<=op[i][0];j++){
            cout<<op[i][j]<<" ";
        }
        cout<<endl;
    }
}