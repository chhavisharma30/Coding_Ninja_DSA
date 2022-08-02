//first approach : perform d shifts one by one drawback is lots of work to be done
/*#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int d;
    cin>>d;
    while(d--){
        int temp = a[0];
        for(int i=0;i<n-1;i++){
            a[i]=a[i+1];
        }
        a[n-1]=temp;
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}*/

//another approach : shift directly by d elements
/*#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int d;
    cin>>d;
    int arr[d];
    for(int i=0;i<d;i++){
        arr[i]=a[i];
    }
    for(int i=0;i<n-d;i++){
        a[i]=a[i+d];
    }
    int k=0;
    for(int i=n-d;i<n;i++){
        a[i]=arr[k];
        k++;
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}*/

//third approach : reverse the array then reverse last d elements and first n-d elements
#include<iostream>
using namespace std;

void rev(int a[],int si,int ei){
    while(si<ei){
        int temp = a[si];
        a[si]=a[ei];
        a[ei]=temp;
        si++;
        ei--;
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int d;
    cin>>d;

    rev(a,0,n-1);
    rev(a,0,n-d-1);
    rev(a,n-d,n-1);
    
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    
}