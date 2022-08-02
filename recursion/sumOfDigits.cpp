//to calculate sum of digits of an integer

#include<iostream>
using namespace std;

int sum(int num){
    if (num<10)
    {
        return num;
    }
    int ans = sum(num/10);
    return ans + (num%10);
}
int main(){
    int n;
    cin>>n;
    cout<<sum(n)<<endl;
}