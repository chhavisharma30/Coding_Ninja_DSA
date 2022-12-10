#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main(){
    unordered_map<string,int> ourmap;
    ourmap["abc1"]=1;
    ourmap["abc2"]=2;
    ourmap["abc3"]=3;
    ourmap["abc4"]=4;
    ourmap["abc5"]=5;
    ourmap["abc6"]=6;
    unordered_map<string,int>::iterator it = ourmap.begin();
    while (it!=ourmap.end())
    {
        cout<<"Key: " <<it->first<<" Value: "<<it->second<<endl;
        it++;
    }
    
    //find func is used to find any value in map by providing key
    unordered_map<string,int>::iterator it2=ourmap.find("abc"); 
    ourmap.erase(it2);//we can pass iterator in erase func

}