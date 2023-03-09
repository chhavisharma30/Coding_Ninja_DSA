/*You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k smallest numbers from given array. You need to save them in an array and return it.
Time complexity should be O(nlogk) and space complexity should be not more than O(k).
Order of elements in the output is not important.
Input Format :
Line 1 : Size of array (n)
Line 2 : Array elements (separated by space)
Line 3 : Integer k

Output Format :
k smallest elements

Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
4

Sample Output 1 :
5
3
2
1*/
#include<iostream>
#include<queue>
using namespace std;

void kSmallestElements(int a[], int n,int k){

    priority_queue<int> pq;

    //inserting first k elements in priority queue
    for(int i=0;i<k;i++){
        pq.push(a[i]);
    }

    //comparing remainig next n-k elements with max element of queue and replacing it if it is smaller
    for(int i=k;i<n;i++){
        if(pq.top()>a[i]){
            pq.pop();
            pq.push(a[i]);
        }
    }

    //storing k smallest elements in an array
    int ans[k];
    int i=0;
    while(!pq.empty()){
        ans[i]=pq.top();
        pq.pop();
        i++;
    }

    for(int i=0;i<k;i++){
        cout<<ans[i]<<" ";
   }
}

int main(){
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    int a[n];
    cout<<"Enter array elements : ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cout<<"Enter k : ";
    cin>>k;
    int *p;

   kSmallestElements(a,n,k);
   

}