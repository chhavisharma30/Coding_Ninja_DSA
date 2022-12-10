/*You have been given two integer arrays/list(ARR1 and ARR2) of size N and M, respectively. You need to print their intersection; An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words, when there is a common value that exists in both the arrays/lists.
Sample Input 1 :
2
6
2 6 8 5 4 3
4
2 3 4 7 
2
10 10
1
10

Sample Output 1 :
2 3 4
10

Sample Input 2 :
1
4
2 6 1 2
5
1 2 3 4 2

Sample Output 2 :
1 2 2*/
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> intersectionPoint(int a1[],int a2[],int n, int m){
    vector<int> output;
    unordered_map<int,int> freq;
    for(int i=0;i<n;i++){
        freq[a1[i]]++;
    }
    
    for(int i=0;i<m;i++){
        if(freq.count(a2[i])){
            output.push_back(a2[i]);
            freq[a2[i]]--;
        }
        if(freq[a2[i]]==0){
            freq.erase(a2[i]);
        }
    }

    return output;
}

int main(){
    int n,m;
    cin>>n;
    int a1[n];
    for(int i=0;i<n;i++){
        cin>>a1[i];
    }
    cin>>m;
    int a2[m];
    for(int i=0;i<m;i++){
        cin>>a2[i];
    }
    vector<int> output = intersectionPoint(a1,a2,n,m);
    for(int i=0;i<output.size();i++){
        cout<<output[i]<<" ";
    }
}