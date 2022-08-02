//count the no of zeroes in a given integer

#include<iostream>
using namespace std;

int zeroes(int num){
    if (num==0)
    {
        return 0;
    }
    int ans = zeroes(num/10);
    if(num%10==0){
        return ans+1;
    }
    else{
        return ans;
    }
}
int main(){
    int n;
    cin>>n;
    cout<<zeroes(n)<<endl;
}