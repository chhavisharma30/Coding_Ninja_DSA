#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main(){
    unordered_map<string,int> myMap;

    //insert
    pair<string,int> p("one",1);
    myMap.insert(p);

    myMap["two"]=2;
    myMap["two"]++;

    //search
    cout<<myMap.at("one")<<endl;
    cout<<myMap["two"]<<endl;

    //size
    cout<<myMap.size()<<endl;

    //searching a key which does not exist
    cout<<myMap["three"]<<endl;     
    //cout<<myMap.at("three")<<endl;    gives exception

    cout<<myMap.size()<<endl;

    //check presence
    if(myMap.count("three")>0)
        cout<<"three is present!"<<endl;

    //erase
    myMap.erase("three");

    cout<<myMap.size()<<endl;
}