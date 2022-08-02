//Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
//Return empty string for numbers 0 and 1.

#include<iostream>
using namespace std;

int keypad(int num,string output[]){
    if(num==0|| num==1){
        output[0]="";
        return 1;
    }
    int n = num%10;
    num = num/10;
    string input;
    int smallopsize= keypad(num,output);
    switch(n){
         case 2: input = "abc";
                break;
            case 3: input = "def";
                break;
            case 4: input = "ghi";
                break;
            case 5: input = "jkl";
                break;
            case 6: input = "mno";
                break;
            case 7: input = "pqrs";
                break;
            case 8: input = "tuv";
                break;
            case 9: input = "wxyz";
                break;
    }
    int ans_size = smallopsize*(input.size());
    string temp[ans_size];
    int k =0;
    for(int i=0;i<smallopsize;i++){
        for(int j=0;j<input.size();j++){
            temp[k]=output[i]+input[j];
            k++;
        }
    }
    for(int i=0;i<ans_size;i++){
        output[i]=temp[i];
    }

    return ans_size;
}

int main(){
    int n;
    cin>>n;
    string* op = new string[1000000];
    int size = keypad(n,op);
    for(int i=0;i<size;i++){
        cout<<op[i]<<endl;
    }
}