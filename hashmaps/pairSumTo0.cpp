/*Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.
Note: Array A can contain duplicate elements as well.

Sample Input 1:
5
2 1 -2 2 3

Sample Output 1:
2

*/
#include<iostream>
#include<unordered_map>
using namespace std;

int countPairs(int a[],int n){
    unordered_map<int,int> freq;
    int count=0;
    for(int i= 0;i<n;i++){
        freq[a[i]]++;
    }
    for(auto i=freq.begin();i!=freq.end();i++){
        if(i->first==0){
            count+=(i->second*((i->second)-1));
        }
        else if(freq.count(-(i->first))){
            auto it = freq.find(-(i->first));
            count += (i->second*(it->second));
        }
    }
    return count/2;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<countPairs(a,n)<<endl;
    return 0;
}