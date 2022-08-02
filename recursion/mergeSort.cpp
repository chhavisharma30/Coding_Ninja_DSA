

#include<iostream>
using namespace std;

void merge(int a[],int si,int mid,int ei){

    int arr[ei-si+1];

    int i,j,k;
    i=si;
    j=mid+1;
    k=0;

    while(i<mid+1 && j<ei+1){
        if(a[i]<=a[j]){
            arr[k]=a[i];
            i++;
        }
        else{
            arr[k]=a[j];
            j++;
        }
        k++;
    }

    while(i<mid+1){
        arr[k]=a[i];
        i++;
        k++;
    }

    while (j<ei+1)
    {
        arr[k]=a[j];
        j++;
        k++;
    }
    
    for(int i=0;i<k;i++){
        a[si]=arr[i];
        si++;
    }
}

void mergesort(int a[], int si, int ei){
    if(si>=ei){
        return;
    }
    int mid = (si+ei)/2;
    mergesort(a,si,mid);
    mergesort(a,mid+1,ei);
    merge(a,si,mid,ei);
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}