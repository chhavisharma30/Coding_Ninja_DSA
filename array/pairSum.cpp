//first approach : use two loops and compare if sum == given sum O(n^2)
//second approach : use sorted array and two pointers method but this is not good if there are duplicate elements O(nlogn) O(m+n)

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
    int sum;
    cin>>sum;

    sort(a,a+n);

    int i=0;
    int j=n-1;

    while(i<j){
        if(a[i]+a[j]==sum){
            cout<<a[i]<<" "<<a[j]<<endl;
            i++;
            j--;
        }
        else if(a[i]+a[j]>sum){
            j--;
        }
        else{
            i++;
        }
    }
}
*/


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
    int sum;
    cin>>sum;

    sort(a,a+n);
}