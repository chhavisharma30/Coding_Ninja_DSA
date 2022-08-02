//to check if an array is sorted
#include<iostream>
using namespace std;

//first method
bool is_sorted2(int a[],int size){
     if(size==0||size==1){
        return true;
    }
    bool isSmallerSorted=is_sorted2(a+1,size-1);
    if(!isSmallerSorted)
        return false;
    if(a[0]>a[1])
        return false;
    else
        return true;
    
}

//second method
/*bool is_sorted(int a[],int size){
    if(size==0||size==1){
        return true;
    }
    if(a[0]>a[1]){
        return false;
    }
    bool isSmallerSorted=is_sorted(a+1,size-1);
    return isSmallerSorted;
}*/
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<is_sorted2(a,n)<<endl;
}