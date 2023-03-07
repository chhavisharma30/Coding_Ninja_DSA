#include<iostream>
#include<queue>
using namespace std;

int main(){
    
    int k;
    cin>>k;
    int a[k][50];
    for(int i=0;i<k;i++){
        int n;
        cin>>n;
        a[i][0]=n;
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
           
        }
    }
    priority_queue<int> pq;
    int j;
    for(int i=0;i<k;i++){
        pq.push(a[i][1]);
    }
    cout<<pq.top()<<" ";
    pq.pop();
}