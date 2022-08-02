//Given two integers M & N, calculate and return their multiplication using recursion. You can only use subtraction and addition for your calculation. No other operators are allowed.

#include<iostream>
using namespace std;
int pro(int m,int n){
    if(n<=0){
        return 0;
    }
    int ans = pro(m,n-1);
    return ans+m;
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<pro(a,b)<<endl;
}