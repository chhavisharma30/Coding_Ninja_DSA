//print all possible subests of an array

//backtracking approach
#include<iostream>
using namespace std;

void printsubs(int a[],int i,int n,int subs[],int j){
    if(i==n){
        int idx =0;
        while(idx<j){
            cout<<subs[idx]<<" ";
            ++idx;
        }
        cout<<endl;
        return;
    }
    
    //when excluding i
    printsubs(a,i+1,n,subs,j);

    //when including i
    subs[j]=a[i];
    printsubs(a,i+1,n,subs,j+1);
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int subs[100];
    printsubs(a,0,n,subs,0);
}