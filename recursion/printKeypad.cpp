//Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
#include <iostream>
#include <string>
using namespace std;

void print(int num,string out){
    if(num==0)
    {
        cout<<out<<endl;
        return ;
    }
    string s[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string input=s[num%10];
    for(int i=0;i<input.size();i++){
        print(num/10,input[i]+out);
    }
}
void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
     print(num,"");
}

int main(){
    int num;
    cin >> num;
    printKeypad(num);
    return 0;
}