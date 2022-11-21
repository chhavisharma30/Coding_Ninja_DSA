/*You are given an array of integers that contain numbers in random order. Write a program to find and return the number which occurs the maximum times in the given input.
If two or more elements contend for the maximum frequency, return the element which occurs in the array first.*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int maxFreq(int *a ,int size){
    int max=0;
    int output;
    unordered_map<int,int> freq;
    for(int i=0;i<size;i++){
        freq[a[i]]++;
        if(freq[a[i]]>max){
            max=freq[a[i]];
        }
    }

    for(int i=0;i<size;i++){
        if(freq[a[i]]==max){
            output=a[i];
        }
    }
    return output;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int output = maxFreq(a,n);
    cout<<output<<endl;
}