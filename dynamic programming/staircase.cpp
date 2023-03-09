/*A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or 3 steps at a time. 
Implement a method to count and return all possible ways in which the child can run-up to the stairs.
Input format :
The first and the only line of input contains an integer value, 'n', denoting the total number of steps.

Output format :
Print the total possible number of ways.

Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec

Sample Input 1:
4

Sample Output 1:
7

Sample Input 2:
10

Sample Output 2:
274*/
#include<iostream>
using namespace std;

//BRUTE FORCE APPROACH - O(3^n)
int allWays(int n){
    //base case
    if(n<=1){
        return 1;
    }
    else if(n==2){
        return 2;
    }
    else
    return allWays(n-3)+allWays(n-2)+allWays(n-1);
    
}

//MEMOIZATION APPROACH - O(n)
int allWaysHelper(int n,int* ans){
    if(n<=1){
        return 1;
    }
    else if(n==2){
        return 2;
    }
    
    if(ans[n]!=-1){
        return ans[n];
    }
    int a = allWaysHelper(n-3,ans);
    int b = allWaysHelper(n-2,ans);
    int c = allWaysHelper(n-1,ans);
    ans[n]=a+b+c;
    return ans[n];
}

int allWays2(int n){
    int* ans = new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i]=-1;
    }
    return allWaysHelper(n,ans);
}

//DP APPROACH - O(n)
int allWays3(int n){
    int* ans = new int[n+1];
    ans[0]=1;
    ans[1]=1;
    ans[2]=2;
    for(int i=3;i<=n;i++){
        ans[i]=ans[i-1]+ans[i-2]+ans[i-3];
    }
    return ans[n];
}

int main(){
    int n;
    cout<<"Enter n : " ;
    cin>>n;
    cout<<allWays(n)<<endl;
    cout<<allWays2(n)<<endl;
    cout<<allWays3(n)<<endl;
}