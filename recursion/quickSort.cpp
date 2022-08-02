#include<iostream>
using namespace std;

int partition(int a[], int si, int ei){
    int pivot = a[si];
    int count = 0;
    int i=si+1;
    for(;i<=ei;i++){
        if(a[i]<pivot){
            count++;
        }
    }

    
    int loc = si+count;
    int temp = a[si];
    a[si]=a[loc];
    a[si+count]=temp;

    int p1,p2;
    p1 = si;
    p2 = ei;

    while(p1<loc && p2>loc){
        if(a[p1]<a[loc]){
            p1++;
        }
        else if(a[p2]>a[loc]){
            p2++;
        }
        else{
            int t=a[p1];
            a[p1]= a[p2];
            a[p2]=t;
        }
    }
    return loc;
}

void qs(int a[], int si,int ei){
    if(si>=ei){
        return;
    }
    int c = partition(a,si,ei);
    qs(a,si,c-1);
    qs(a,c+1,ei);
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    qs(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}