/*You have been given an integer array/list(ARR) and a number 'num'. Find and return the total number of pairs in the array/list which sum to 'num'.
Note:
Given array/list can contain duplicate elements.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the first array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.

Third line contains an integer 'num'.

Output format :
For each test case, print the total number of pairs present in the array/list.

Output for every test case will be printed in a separate line.

Constraints :
1 <= t <= 10^2
0 <= N <= 10^4
0 <= num <= 10^9

Time Limit: 1 sec*/

//first approach : use two loops and compare if sum == given sum O(n^2)   can be implemented easily
//second approach : use sorted array and two pointers method O(nlogn)+O(n)    implemented below


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//function to get count of a particular element of array
int getcount(int a[],int n,int m){
    int count=0;
    for(int i=0;i<n;i++){
        if(a[i]==m){
            count++;
        }
    }
    return count;
}

//function to count no of pairs whose sum equals to a soecific number
int countpairs(int a[],int n, int sum){
    int i=0;
    int j=n-1;
    int pairs=0;
    while(i<j){
        if(a[i]+a[j] == sum){
            if(a[i]!=a[j]){
                int c1 = getcount(a,n,a[i]);
                int c2 = getcount(a,n,a[j]);
                pairs = pairs + (c1*c2);
                i=i+c1;
                j=j-c2;
            }
            else{
                int c = getcount(a,n,a[i]);
                pairs = pairs + ((c*c-1)/2);
                i=i+c;
                j=j-c;
            }
        }
        else if(a[i]+a[j]>sum){
            j--;
        }
        else{
            i++;
        }
    }
    return pairs;
}

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

    int pairs = countpairs(a,n,sum);
    cout<<pairs<<endl;
}