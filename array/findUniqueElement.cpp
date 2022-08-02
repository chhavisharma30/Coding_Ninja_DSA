/*You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].
Now, in the given array/list, 'M' numbers are present twice and one number is present only once.
You need to find and return that number which is unique in the array/list.*/

//o(n^2)
/*#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n;i++){
        int flag = 0;
        for(int j=0;j<n;j++){
            if(a[i] == a[j] && i != j){
                flag=1;
                break;
            }
        }
        if(flag==0){
            cout<<a[i];
            return 0;
        }
    }
}*/

//O(nlogn)
/*#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(a[i]==a[i+1]){
            i++;
        }
        else{
            cout<<a[i];
        }
    }
}*/

//O(n)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int xorr=0;
    for(int i=0;i<n;i++){
        xorr ^= a[i];
    }
    cout<<xorr<<endl;
}