#include<iostream>
#include<vector>    //header file to be included to use vector
using namespace std;

int main(){
    //vector<int> *vp = new vector<int>();  dynamically allocating a vector
    vector<int> v;  //static allocation

    for(int i=0;i<100;i++){
        cout<<"capacity : "<<v.capacity()<<endl;   //this func gives the current max size of vector array
        cout<<"size : "<<v.size()<<endl;   //this func gives the no of elements stored in vector array 
        v.push_back(i+1);   //this func is used to insert elements in vector array
    }

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    v[1]=100;   //we can update data of vector array using square brackets same as in a normal array

    /*Never use square brackets for inserting elements in an array, it doesn't give an error but when we insert element using this method, the vector doesn't increase its size even if the array is fully filled, so in that case our data can be stored in an out of range memeory which is not a good thing 
    In pushback(), vector checks it size and doubles it if needed
    Moreover if we insert through square brackets and then use pushback for insertion, the data updated by the [] will not be stored and the pushback will insert element at that position only from where the previous element was inserted through pushback()
    v[103]=1234;
    v[104]=5678;*/

    v.push_back(23);
    v.push_back(334);

    v.pop_back();   //this func is used to delete the last element from the vector array

    /*for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;   we can use square brackets to access the vector array elements
    }*/

    //we can also use the at() to get the element stored at a specific position and it is also safer to use than the [] because when we use [] to access the element we can even access any out of range value which will print garbage but by using at() if we try to access any out of range element then it gives an error that you are accessing the position exceeding size of the vector array
    cout<<v.at(2)<<endl;
    cout<<v.at(8)<<endl;

}