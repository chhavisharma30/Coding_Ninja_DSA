//k sorted array(in notes)
#include<iostream>
#include<queue>
using namespace std;

void kSortedArray(int a[],int n,int k){
    priority_queue<int> pq;
    
    //inserting first k elements in priority queue : complexity (klogk) 
    for(int i=0;i<k;i++){
        pq.push(a[i]);
    }

    //sorting first n-k elements : complexity ((n-k)logk)
    int j=0;
    for(int i=k;i<n;i++){
        a[j]=pq.top();
        pq.pop();
        pq.push(a[i]);
        j++;
    }

    //sorting remaining k elements : complexity (klogk)
    while(!pq.empty()){
        a[j]=pq.top();
        pq.pop();
        j++;
    }
}

int main(){
    int a[] = {10,12,6,7,9};
    int k=3;
    kSortedArray(a,5,k);
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
}

//total complexity = klogk+nlogk-klogk+klogk = (n+k)logk
//if k<<<<n then O(nlogk)= O(n)