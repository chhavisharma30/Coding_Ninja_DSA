//You have been given two integer arrays/list(ARR1 and ARR2) of size N and M, respectively. You need to print their intersection; An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words, when there is a common value that exists in both the arrays/lists.

//first approach : comapre every element of array1 with array2 by using loops O(m*n)
//second approch : sort the smalller array and then apply binary search O(nlogn)+O(mlogn) it'll not work for duplicate elements
//third approach : sort both arrays and compare O(nlogn)+O(nlogm)+O(m+n)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a1[n];
    for(int i=0;i<n;i++){
        cin>>a1[i];
    }
    int m;
    cin>>m;
    int a2[m];
    for(int i=0;i<m;i++){
        cin>>a2[i];
    }

    sort(a1,a1+n);
    sort(a2,a2+m);


    int i=0;
    int j=0;
    
    while(i!=n || j!=m){
        if(a1[i]==a2[j]){
            cout<<a1[i]<<" ";
            i++;
            j++;
        }
        else if(a1[i]<a2[j]){
            i++;
        }
        else{
            j++;
        }
    }
}