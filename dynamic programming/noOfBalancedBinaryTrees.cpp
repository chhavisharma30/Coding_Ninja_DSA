/*Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so return output modulus 10^9 + 7.
Input Format :
Integer h

Output Format :
Count % 10^9 + 7

Input Constraints :
1 <= h <= 40

Sample Input 1:
3

Sample Output 1:
15

Sample Input 2:
4

Sample Output 2:
315*/
#include<iostream>
#include<cmath>
using namespace std;

//BRUTE FORCE APPROACH - O(2^h)
/*For solving the problem, let us first fix the root node at level 1. Since we have fixed the root node we have N-1 levels left, 
now we have to count the number of ways we can create a balanced binary tree of height (N-1) at the left 
and the right subtree of the root node; hence we have reduced the problem from finding the number of balanced binary trees 
with height ‘N’ to finding the number of balanced binary trees with height ‘N-1’. 
This substructure property paves the way for a recursive solution.

For finding the number of balanced binary trees with height ‘N’, we will fix the root node, 
and then we will have the following possibilities:

The left subtree has a height (N-1), and the right subtree has a height (N-2).
The left subtree has a height (N-2), and the right subtree has a height (N-1).
Both the left subtree and the right subtree have a height (N-1).
 

The steps are as follows:

Let’s define a function countTree(height) which will return the number of balanced binary trees of height “height”.
The base case for this function will be when ‘height’ is either 0 or 1. We will have one balanced binary tree in both cases. In the case of 0, the tree will be NULL without any nodes, and for height=1, it will be a single root node.
Otherwise, we will recur for the left and right subtree with height “height-1” and cover the three possibilities mentioned above.
countTree(height-1) * countTree(height-2) {Multiplication because of independent events, i.e. our left combination doesn’t affect the right combination.}
countTree(height-2) * countTree(height-1) {Multiplication because of independent events, i.e. our left combination doesn’t affect the right combination.}
countTree(height-1) * countTree(height-1) {Multiplication because of independent events, i.e. our left combination doesn’t affect the right combination.}
The final answer will be the sum of the three values(Sum because of dependent events. I.e. at a time only one event can occur out of three) returned by the recursive function calls modulo 10^9+7.*/
int noOfBT(int h){
    //base case
    if(h<=1){
        return 1;
    }

    //recursive call
    int mod = (int)(pow(10,9))+7;
    int a = noOfBT(h-1);
    int b = noOfBT(h-2);

    //small calculation
    int  temp1= (int)(((long)(a)*a)%mod);
    int  temp2= (int)((2*(long)(a)*b)%mod);
    int ans = (temp1+temp2)%mod;
    return ans;
}

//MEMOIZATION APPROACH - O(h)
int BTHelper(int h,int* ans){
    if(h<=1){
        return 1;
    }
    if(ans[h]!=-1){
        return ans[h];
    }
    int mod = (int)(pow(10,9))+7;
    int a = BTHelper(h-1,ans);
    int b = BTHelper(h-2,ans);

    //small calculation
    int  temp1= (int)(((long)(a)*a)%mod);
    int  temp2= (int)((2*(long)(a)*b)%mod);
    int res = (temp1+temp2)%mod;
    ans[h]=res;
    return ans[h];
}

int noOfBT2(int h){
    int* ans =new int[ h+1];
    for(int i=0;i<=h;i++){
        ans[i]=-1;
    }
    return BTHelper(h,ans);
}

//DP APPROACH - O(h)
int noOfBT3(int h){
    int* ans = new int[h+1];
    ans[0]=1;
    ans[1]=1;
    int mod = (int)(pow(10,9))+7;
    for(int i=2;i<=h;i++){
        ans[i] = ((((ans[i-1]%mod)*(ans[i-1]%mod))%mod) + ((2*(ans[i-1]%mod)*(ans[i-2]%mod))%mod))%mod;
    }
    return ans[h]%mod;
}

int main(){
    int h;
    cout<<"Enter height of tree : ";
    cin>>h;
    cout<<noOfBT(h)<<endl;
    cout<<noOfBT2(h)<<endl;
    cout<<noOfBT3(h)<<endl;
}