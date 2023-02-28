/*You are given with an array of integers and an integer K. You have to find and print the count of all such pairs which have difference K.
Note: Take absolute difference between the elements of the array.
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol n.
The following line contains n space separated integers, that denote the value of the elements of the array.
The following line contains an integer, that denotes the value of K.

Output format :
The first and only line of output contains count of all such pairs which have an absolute difference of K.

Constraints :
0 <= n <= 10^4
Time Limit: 1 sec

Sample Input 1 :
4 
5 1 2 4
3

Sample Output 1 :
2

Sample Input 2 :
4
4 4 4 4 
0

Sample Output 2 :
6
*/

//Note : its array implementation takes O(n^2) time.

#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<int,int> map;
    int n,k;
    cout<<"Enter size of the array : "<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter array elements : "<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(map.count(a[i])>0){
            map[a[i]]++;
        }
        else{
            pair<int,int> p(a[i],1);
            map.insert(p);
        }
    }
    cout<<"Enter k : "<<endl;
    cin>>k;

    int pair=0;

    //this approach is taking frequencies according to the array traversed
    /*for(int i=0;i<n;i++){
        if(k==0){
            pair+=map[a[i]]-1;
        }
        else 
        {if(map.count(a[i]+k)>0){
            pair+=map[a[i]+k];
        }
        if(map.count(a[i]-k)>0){
            pair+=map[a[i]-k];
        }
        }
        map[a[i]]=map[a[i]]-1;
    }*/

    //this approach is considering frequencies at one go considering all occurances of that number
    for(int i=0;i<n;i++){
        if(k==0){
            pair+=map[a[i]]-1;
            map[a[i]]--;
        }
        else{
        if(map.count(a[i]+k)>0){
            pair += map[a[i]]*map[a[i]+k];
        }
        if(map.count(a[i]-k)>0){
            pair += map[a[i]]*map[a[i]-k];
        }
        map.erase(a[i]);
        }
    }

    cout<<"Total pairs are : "<<pair<<endl;
}