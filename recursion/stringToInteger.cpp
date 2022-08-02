//Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.

#include <iostream>
#include<cmath>
using namespace std;

/*int convert(string s)
{
    if (s.length() == 1)
    {
        int i = s[0] - '0';
        return i;
    }


    double so=convert(s.substr(1));
    double num = s[0] - '0';
    int l =s.length();
    double ans = (num* pow(10,l-1)) + so ;
    return (int)ans;
}*/
int convert1(string s){
    if(s.length()==1){
        int i=s[0]-'0';
        return i;
    }

    int so = convert1(s.substr(0,s.length()-1));
    int num = s[s.length()-1]-'0';
    int ans=so*10+num;
    return (int)ans;
}

int main()
{
    string s;
    cin >> s;
    cout << convert1(s) << endl;
}