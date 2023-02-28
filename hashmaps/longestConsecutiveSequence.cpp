/*You are given an array of unique integers that contain numbers in random order. You have to find the longest possible sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains starting and ending element. If the length of the longest possible sequence is one, then the output array must contain only single element.
Note:
1. Best solution takes O(n) time.
2. If two sequences are of equal length, then return the sequence starting with the number whose occurrence is earlier in the array.

Input format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol n.
The following line contains n space separated integers, that denote the value of the elements of the array.

Output format:
The first and only line of output contains starting and ending element of the longest consecutive sequence. If the length of longest consecutive sequence, then just print the starting element.

Constraints :
0 <= n <= 10^6
Time Limit: 1 sec

Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6

Sample Output 1 :
8 12

Sample Input 2 :
7
3 7 2 1 9 8 41

Sample Output 2 :
7 9
Explanation: Sequence should be of consecutive numbers. 
Here we have 2 sequences with same length i.e. [1, 2, 3] and [7, 8, 9], but we should select [7, 8, 9] 
because the starting point of [7, 8, 9] comes first in input array and therefore, 
the output will be 7 9, as we have to print starting and ending element of the longest consecutive sequence.

Sample Input 3 :
7
15 24 23 12 19 11 16

Sample Output 3 :
15 16*/

//Note: can be solved by srray sorting in O(nlogn)
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;


//logic is to first create map entries for all array members with value 1, then increasing corresponding value of element in map until we are getting consecutive elements.
//after whole array is traversed, then the entry with highest value is stored and becomes lcs.
//this solution is O(n)
int main(){
    unordered_map<int,int> map;
    //unordered_map<int,bool> map;
    int n;
    cout<<"Enter size of array : "<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the elements of array : "<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
        map[a[i]]=1;
    }
    for(int i=0;i<n;i++){
        int temp=a[i];
        while(map.count(temp+1)>0){
            map[a[i]]++;
            temp++;
        }
    }

    int l=0;
    int start = 0;
    for(int i=0;i<n;i++){
        if(map[a[i]]>l){
            l=map[a[i]];
            start = a[i];
        }
    }

    cout<< "Longest Consecutive Sequence : "<<start<<" "<<start+l-1<<endl;


    //second method
    /*initialize all entry with true
    traverse for lcs forward and backward sides both
    compare with max length and finally lcs is obtained*/
    //this method has same time complexity but it avoids redundant work

    /*unordered_map<int,bool> map;
    for(int i=0;i<n;i++){
        cin>>a[i];
        map[a[i]]=true;
    }

    int maxlen=0;
    int start=0;
    for(int i=0;i<n;i++){
        int temp=a[i];
        int lenc=1;
        int startc=a[i];
        while(map.count(temp+1)>0){
            map[temp+1]=false;
            temp++;
            lenc++;
        }
        temp=a[i];
        int lenb=1;
        int startb=a[i];
        while(map.count(temp-1)>0){
            map[temp-1]=false;
            startb=temp-1;
            temp--;
            lenb++;
        }

        if(lenb>lenc){
            if(maxlen<lenb){
                maxlen=lenb;
                start=startb;
            }
        }
        else{
            if(maxlen<lenc){
                maxlen=lenc;
                start=startc;
            }
        }
    }

    cout<< "Longest Consecutive Sequence : "<<start<<" "<<start+maxlen-1<<endl;*/
}