//Given k, find the geometric sum i.e.
//1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k)

//using recursion.


#include<iostream>
#include<cmath>
using namespace std;

double gsum(int k){
    if(k==0){
        return 1;
    }
    double so=gsum(k-1);
    double ans=so + (1/(pow(2,k)));
    return ans;
}

int main(){
    int k;
    cin>>k;
    cout<<gsum(k)<<endl;
}