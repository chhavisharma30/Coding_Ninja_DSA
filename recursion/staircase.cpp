//A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return number of possible ways W.

#include<iostream>
using namespace std;

int stair(int n){
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    return stair(n-1)+stair(n-2)+stair(n-3);
}

int main(){
    int n;
    cin>>n;
    cout<<stair(n)<<endl;
}