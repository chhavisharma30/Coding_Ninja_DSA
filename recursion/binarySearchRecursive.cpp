#include<iostream>
using namespace std;

int binarysearch(int a[],int si,int ei,int key){
    if(si>ei){
        return -1;
    }
    int mid = (si+ei)/2;
    if(key==a[mid]){
        return mid;
    }
    else if(key>a[mid]){
        binarysearch(a,mid+1,ei,key);
    }
    else{
        binarysearch(a,si,mid-1,key);
    }

}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int key;
    cin>>key;
    cout<<binarysearch(a,0,n-1,key)<<endl;
}