/*Given an array of integers, check whether it represents max-heap or not. Return true if the given array represents max-heap, else return false.
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.

Output Format :
The first and only line of output contains true if it represents max-heap and false if it is not a max-heap.

Constraints:
1 <= N <= 10^5
1 <= Ai <= 10^5
Time Limit: 1 sec

Sample Input 1:
8
42 20 18 6 14 11 9 4

Sample Output 1:
true*/

#include<iostream>
#include<queue>
using namespace std;

bool checkMaxHeap(int a[],int n){

    int parentIndex=0;
    int lchildIndex = 2*parentIndex+1;
    int rchildIndex = 2*parentIndex+2;

    while(lchildIndex<n){
        if(a[lchildIndex]>a[parentIndex]){
            return false;
        }
        if(rchildIndex<n && a[rchildIndex]>a[parentIndex]){
            return false;
        }

        parentIndex++;
        lchildIndex = 2*parentIndex+1;
        rchildIndex = 2*parentIndex+2;
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<checkMaxHeap(a,n)<<endl;
}