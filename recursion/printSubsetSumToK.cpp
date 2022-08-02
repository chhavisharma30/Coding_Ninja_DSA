#include <iostream>
using namespace std;

void printsubs(int a[],int i,int n,int subs[],int j,int k){
    if(i==n){
        if(k==0){
            int idx=0;
            while(idx<j){
                cout<<subs[idx]<<" ";
                ++idx;
            }
            cout<<endl;
            return;
        }
        else{
            return;
        }
    }

    printsubs(a,i+1,n,subs,j,k);

    subs[j]=a[i];
    printsubs(a,i+1,n,subs,j+1,k-a[i]);
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cin>>k;
    int subs[100];
    printsubs(a,0,n,subs,0,k);

}