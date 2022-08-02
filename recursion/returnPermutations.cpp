//Given a string S, find and return all the possible permutations of the input string.

#include<iostream>
using namespace std;

int returnPermutations(string input, string output[]){
    if(input.length() == 0){
        output[0] = ""; 
        return 1;
        }
    
    string smallOutput[10000];
    int smallSize = returnPermutations(input.substr(1), smallOutput); 
    int k = 0;
    for(int i = 0; i < smallSize; i++){
        for(int j = 0; j <=smallOutput[i].length(); j++){ 
            output[k++] = smallOutput[i].substr(0,j) + input[0] + smallOutput[i].substr(j); 
            
        }
    }
    
    return k;
}

int main(){
    string s;
    cin>>s;
    string op[10000];
    int k=returnPermutations(s,op);
    for(int i=0;i<k;i++){
        cout<<op[i]<<endl;
    }
}